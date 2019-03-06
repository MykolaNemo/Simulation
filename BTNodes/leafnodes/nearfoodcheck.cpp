#include "nearfoodcheck.h"
#include <QRect>
#include <iostream>
#include "behaviours/blackboards/blackboard.h"
#include "models/fieldobject.h"
#include <QGraphicsItem>
#include "models/plant/plant.h"

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

NearFoodCheck::NearFoodCheck(std::string name, BehaviourTree *parent):
    BehaviourTree(name, parent)
{
}

BehaviourTree::ExecuteResult NearFoodCheck::execute(const std::chrono::milliseconds &,
                                                    std::shared_ptr<Blackboard>& blackboard)
{
    std::cout<<getName();
    if(blackboard->food && blackboard->actor)
    {
        Position startPos = blackboard->actor->getPosition();
        Position endPos = calculateDestinationPositionFromTheSide(blackboard->actor, blackboard->food);
        double totalDistance = sqrt(pow(abs(endPos.x - startPos.x),2) + pow(abs(endPos.y - startPos.y),2));
        if(totalDistance == 0)
        {
            std::cout<<": SUCCESS"<<std::endl;
            return BehaviourTree::ExecuteResult::SUCCESS;
        }
    }
    std::cout<<": FAILURE"<<std::endl;
    return BehaviourTree::ExecuteResult::FAILURE;
}
