#include "eatfoodaction.h"

#include "behaviours/blackboards/blackboard.h"
#include "models/animal/animal.h"
#include "models/plant/plant.h"

EatFood::EatFood(std::string name, BehaviourTree *parent)
    : BehaviourTree(std::move(name), parent)
{
}

BehaviourTree::ExecuteResult EatFood::execute(const std::chrono::milliseconds &,
                                                    std::shared_ptr<Blackboard>& blackboard)
{
    if(!blackboard->animal || !blackboard->plant)
    {
        return BehaviourTree::ExecuteResult::FAILURE;
    }
    blackboard->plant->decreaseFoodPoints(1);
    blackboard->animal->decreaseHunger(1);

    if(blackboard->plant->getFoodPoints() == 0)
    {
        blackboard->plant->setAsOccupied(false);
        blackboard->plant = std::shared_ptr<Plant>();
        return BehaviourTree::ExecuteResult::SUCCESS;
    }
    return BehaviourTree::ExecuteResult::RUNNING;
}
