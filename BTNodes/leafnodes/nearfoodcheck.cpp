#include "nearfoodcheck.h"
#include "behaviours/blackboards/blackboard.h"
#include "models/fieldobject.h"
#include "models/plant/plant.h"
#include "models/animal/animal.h"
#include "ECS/Components/graphicscomponent.h"
#include "ECS/Components/positioncomponent.h"

#include <QGraphicsItem>
#include <iostream>

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

IsNearFood::IsNearFood(std::string name, BehaviourTree *parent):
    BehaviourTree(std::move(name), parent)
{
}

BehaviourTree::ExecuteResult IsNearFood::execute(const std::chrono::milliseconds &,
                                                    std::shared_ptr<Blackboard>& blackboard)
{
    std::cout<<"IsNearFood?"<<std::endl;
    if(blackboard->plant && blackboard->actor)
    {
        Position startPos = blackboard->actor->getComponent<PositionComponent>()->getPosition();
        Position endPos = calculateDestinationPositionFromTheSide(blackboard->actor, blackboard->plant);
        double totalDistance = sqrt(pow(abs(endPos.x - startPos.x),2) + pow(abs(endPos.y - startPos.y),2));
        if(totalDistance < 1E-3)
        {
            std::cout<<"IsNearFood success"<<std::endl;
            return BehaviourTree::ExecuteResult::SUCCESS;
        }
        std::cout<<"IsNearFood not close enough"<<std::endl;
    }
    std::cout<<"IsNearFood failure"<<blackboard->plant<<", " << blackboard->actor <<std::endl;
    return BehaviourTree::ExecuteResult::FAILURE;
}
