#include "nearfoodcheck.h"
#include "behaviours/blackboards/blackboard.h"
#include "models/fieldobject.h"
#include "models/plant/plant.h"
#include "models/animal/animal.h"

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

IsNearFood::IsNearFood(std::string name, BehaviourTree *parent):
    BehaviourTree(std::move(name), parent)
{
}

BehaviourTree::ExecuteResult IsNearFood::execute(const std::chrono::milliseconds &,
                                                    std::shared_ptr<Blackboard>& blackboard)
{
    if(blackboard->food && blackboard->animal)
    {
        Position startPos = blackboard->animal->getPosition();
        Position endPos = calculateDestinationPositionFromTheSide(blackboard->animal, blackboard->food);
        double totalDistance = sqrt(pow(abs(endPos.x - startPos.x),2) + pow(abs(endPos.y - startPos.y),2));
        if(totalDistance < 1E-3)
        {
            return BehaviourTree::ExecuteResult::SUCCESS;
        }
    }
    return BehaviourTree::ExecuteResult::FAILURE;
}
