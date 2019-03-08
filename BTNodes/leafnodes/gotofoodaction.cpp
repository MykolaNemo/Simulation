#include "gotofoodaction.h"

#include "behaviours/blackboards/blackboard.h"
#include "models/field.h"
#include "models/animal/animal.h"
#include "models/plant/plant.h"

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

GoToFoodAction::GoToFoodAction(std::string name, BehaviourTree *parent):
    BehaviourTree(std::move(name), parent)
{
}

BehaviourTree::ExecuteResult GoToFoodAction::execute(const std::chrono::milliseconds &tick,
                                                     std::shared_ptr<Blackboard>& blackboard)
{
//    std::cout<<getName()<<": ";
    if(!blackboard->field || !blackboard->animal)
    {
//        std::cout<<"FAILURE 1"<<std::endl;
        return BehaviourTree::ExecuteResult::FAILURE;
    }

    if(!blackboard->food)
    {
        blackboard->food = blackboard->field->getClosestPlant(blackboard->animal->getPosition());
        if(!blackboard->food)
        {
//            std::cout<<"FAILURE 2"<<std::endl;
            return BehaviourTree::ExecuteResult::FAILURE;
        }
        else
        {
            blackboard->food->setAsOccupied(true);
        }
    }

    Data& data = [this, blackboard]()->Data&{
        if(mDataMap.count(blackboard->animal) == 0)
        {
            Data data;
            data.startPoint = blackboard->animal->getPosition();
            data.destinationPoint = calculateDestinationPositionFromTheSide(blackboard->animal,
                                                                            std::static_pointer_cast<FieldObject>(blackboard->food));
//            std::cout<<"New: "<<data.destinationPoint.x<<", "<<data.destinationPoint.y<<std::endl;
            data.totalDistance = sqrt(pow(abs(data.destinationPoint.x - data.startPoint.x),2) +
                                      pow(abs(data.destinationPoint.y - data.startPoint.y),2));
            mDataMap.insert({blackboard->animal, data});
        }
        return mDataMap[blackboard->animal];
    }();

    if(data.totalDistance < 1E-3)
    {
//        std::cout<<"SUCCESS 1"<<std::endl;
        return BehaviourTree::ExecuteResult::SUCCESS;
    }

    double velocity = blackboard->animal->getVelocity();
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

    blackboard->animal->setPosition(Position(x,y));

    if(data.distanceWalked >= data.totalDistance)
    {
//        std::cout<<"SUCCESS 2"<<std::endl;
        mDataMap.erase(blackboard->animal);
        return BehaviourTree::ExecuteResult::SUCCESS;
    }
//    std::cout<<"RUNNING"<<std::endl;
    return BehaviourTree::ExecuteResult::RUNNING;
}
