#include "gotofoodaction.h"

#include "behaviours/blackboards/blackboard.h"
#include "models/field.h"
#include "models/animal/animal.h"
#include "models/plant/plant.h"
#include "ECS/Components/velocitycomponent.h"
#include "ECS/Components/positioncomponent.h"
#include "ECS/Components/graphicscomponent.h"
#include "ECS/Components/canbeoccupiedcomponent.h"

#include <QGraphicsItem>

namespace
{
Position calculateDestinationPositionFromTheSide(const std::shared_ptr<IEntity>& animal,
                                                 const std::shared_ptr<IEntity>& food)
{
    assert(animal && food);

    const QGraphicsItem* animalGraphics = animal->getComponent<GraphicsComponent>()->getGraphics();
    const QGraphicsItem* foodGraphics = food->getComponent<GraphicsComponent>()->getGraphics();
    assert(animalGraphics && foodGraphics);

    const QSize animalSize = animalGraphics->boundingRect().size().toSize();
    const Position animalCenterPoint = animal->getComponent<PositionComponent>()->getPosition() +
            Position(animalSize.width()/2, animalSize.height()/2);

    const QSize foodSize = foodGraphics->boundingRect().size().toSize();
    const Position foodPosition = food->getComponent<PositionComponent>()->getPosition();
    const Position foodCenterPoint = foodPosition + Position(foodSize.width()/2, foodSize.height()/2);

    if(animalCenterPoint.x <= foodCenterPoint.x)
    {
        const int x = foodPosition.x - animalSize.width();
        const int y = foodCenterPoint.y - animalSize.height()/2;
        return Position(x,y);
    }
    else
    {
        const int x = foodPosition.x + foodSize.width();
        const int y = foodCenterPoint.y - animalSize.height()/2;
        return Position(x,y);
    }
}
}

GoToFood::GoToFood(std::string name, BehaviourTree *parent):
    BehaviourTree(std::move(name), parent)
{
}

BehaviourTree::ExecuteResult GoToFood::execute(const std::chrono::milliseconds &tick,
                                                     std::shared_ptr<Blackboard>& blackboard)
{
    if(!blackboard->field || !blackboard->actor)
    {
        return BehaviourTree::ExecuteResult::FAILURE;
    }

    if(!blackboard->plant)
    {
        auto position = blackboard->actor->getComponent<PositionComponent>()->getPosition();
        blackboard->plant = blackboard->field->getClosestPlant(position);
        if(!blackboard->plant)
        {
            return BehaviourTree::ExecuteResult::FAILURE;
        }
        else
        {
            blackboard->plant->getComponent<CanBeOccupiedComponent>()->setAsOccupied(true);
        }
    }

    Data& data = [this, blackboard]()->Data&{
        if(mDataMap.count(blackboard->actor) == 0)
        {
            Data data;
            data.startPoint = blackboard->actor->getComponent<PositionComponent>()->getPosition();
            data.destinationPoint = calculateDestinationPositionFromTheSide(blackboard->actor,
                                                                            blackboard->plant);
            data.totalDistance = sqrt(pow(abs(data.destinationPoint.x - data.startPoint.x),2) +
                                      pow(abs(data.destinationPoint.y - data.startPoint.y),2));
            mDataMap.insert({blackboard->actor, data});
        }
        return mDataMap[blackboard->actor];
    }();

    if(data.totalDistance < 1E-3)
    {
        return BehaviourTree::ExecuteResult::SUCCESS;
    }

    auto movingComp = blackboard->actor->getComponent<VelocityComponent>();
    if(!movingComp)
    {
        return BehaviourTree::ExecuteResult::FAILURE;
    }

    double velocity = movingComp->getVelocity();
    long long microsecondsPast = std::chrono::duration_cast<std::chrono::microseconds>(tick).count();
    data.distanceWalked += velocity*(static_cast<double>(microsecondsPast)/1000000.0);
    if(data.distanceWalked >= data.totalDistance)
    {
        data.distanceWalked = data.totalDistance;
    }
    const auto x = static_cast<int>(static_cast<double>(data.startPoint.x) -
                                    (data.distanceWalked * static_cast<double>(data.startPoint.x - data.destinationPoint.x))/data.totalDistance);
    const auto y = static_cast<int>(static_cast<double>(data.startPoint.y) -
                                    (data.distanceWalked * static_cast<double>(data.startPoint.y - data.destinationPoint.y))/data.totalDistance);

    blackboard->actor->getComponent<PositionComponent>()->setPosition(Position(x,y));

    if(data.distanceWalked >= data.totalDistance)
    {
        mDataMap.erase(blackboard->actor);
        return BehaviourTree::ExecuteResult::SUCCESS;
    }
    return BehaviourTree::ExecuteResult::RUNNING;
}
