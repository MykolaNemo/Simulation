#include "gotofoodaction.h"
#include <iostream>

#include "behaviours/blackboards/blackboard.h"
#include "models/field.h"
#include "models/fieldobject.h"
#include "models/plant/plant.h"

#include <QSize>
#include <QRect>
#include <QGraphicsItem>

namespace
{
Position calculateDestinationPositionFromTheSide(const std::shared_ptr<FieldObject>& animalObject,
                                                 const std::shared_ptr<FieldObject>& foodObject)
{
    assert(animalObject && foodObject);

    const QGraphicsItem* animalGraphics = animalObject->getGraphics();
    const QGraphicsItem* foodGraphics = foodObject->getGraphics();
    assert(animalGraphics && foodGraphics);

    const QSize animalSize = animalGraphics->boundingRect().size().toSize();
    const Position animalCenterPoint = animalObject->getPosition() +
            Position(animalSize.width()/2, animalSize.height()/2);

    const QSize foodSize = foodGraphics->boundingRect().size().toSize();
    const Position foodCenterPoint = foodObject->getPosition() +
            Position(foodSize.width()/2, foodSize.height()/2);

    if(animalCenterPoint.x <= foodCenterPoint.x)
    {
        const int x = foodObject->getPosition().x - animalSize.width();
        const int y = foodCenterPoint.y - animalSize.height()/2;
        return Position(x,y);
    }
    else
    {
        const int x = foodObject->getPosition().x + foodSize.width();
        const int y = foodCenterPoint.y - animalSize.height()/2;
        return Position(x,y);
    }
}
}

const double GoToFoodAction::velocity = 5.0;

GoToFoodAction::GoToFoodAction(std::string name, BehaviourTree *parent):
    BehaviourTree(name, parent)
{

}

BehaviourTree::ExecuteResult GoToFoodAction::execute(const std::chrono::milliseconds &tick,
                                                     std::shared_ptr<Blackboard>& blackboard)
{
    std::cout<<getName()<<": ";
    if(!blackboard->field || !blackboard->actor)
    {
        std::cout<<"FAILURE 1"<<std::endl;
        return BehaviourTree::ExecuteResult::FAILURE;
    }

    if(!blackboard->food)
    {
        blackboard->food = blackboard->field->getClosestPlant(blackboard->actor->getPosition());
        if(!blackboard->food)
        {
            std::cout<<"FAILURE 2"<<std::endl;
            return BehaviourTree::ExecuteResult::FAILURE;
        }
    }

    Data& data = [this, blackboard]()->Data&{
        if(mDataMap.count(blackboard->actor) == 0)
        {
            Data data;
            data.startPoint = blackboard->actor->getPosition();
            data.destinationPoint = calculateDestinationPositionFromTheSide(blackboard->actor,
                                                                            std::static_pointer_cast<FieldObject>(blackboard->food));
            std::cout<<"New: "<<data.destinationPoint.x<<", "<<data.destinationPoint.y<<std::endl;
            data.totalDistance = sqrt(pow(abs(data.destinationPoint.x - data.startPoint.x),2) +
                                      pow(abs(data.destinationPoint.y - data.startPoint.y),2));
            mDataMap.insert({blackboard->actor, data});
        }
        return mDataMap[blackboard->actor];
    }();

    if(data.totalDistance == 0)
    {
        std::cout<<"SUCCESS 1"<<std::endl;
        return BehaviourTree::ExecuteResult::SUCCESS;
    }

    Position oldActorPos = blackboard->actor->getPosition();
    Position foodPos = blackboard->food->getPosition();

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

    blackboard->actor->setPosition(Position(x,y));

    if(data.distanceWalked >= data.totalDistance)
    {
        std::cout<<"SUCCESS 2"<<std::endl;
        mDataMap.erase(blackboard->actor);
        return BehaviourTree::ExecuteResult::SUCCESS;
    }
    std::cout<<"RUNNING"<<std::endl;
    return BehaviourTree::ExecuteResult::RUNNING;


    //    m_distanceWalked += velocity*(static_cast<double>(microsecondsPast)/1000000.0);
    //    if(m_distanceWalked > m_totalDistance)
    //    {
    //        m_distanceWalked = m_totalDistance;
    //    }
    //    const auto x = static_cast<int>(static_cast<double>(m_startPoint.x) -
    //                                    (m_distanceWalked * static_cast<double>(m_startPoint.x - m_destinationPoint.x))/m_totalDistance);
    //    const auto y = static_cast<int>(static_cast<double>(m_startPoint.y) -
    //                                    (m_distanceWalked * static_cast<double>(m_startPoint.y - m_destinationPoint.y))/m_totalDistance);

}
