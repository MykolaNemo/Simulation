#include "eatfoodaction.h"

#include "behaviours/blackboards/blackboard.h"
#include "models/animal/animal.h"
#include "models/plant/plant.h"
//#include <iostream>

EatFood::EatFood(std::string name, BehaviourTree *parent)
    : BehaviourTree(std::move(name), parent)
{
}

BehaviourTree::ExecuteResult EatFood::execute(const std::chrono::milliseconds &,
                                                    std::shared_ptr<Blackboard>& blackboard)
{
    if(!blackboard->animal || !blackboard->food)
    {
        return BehaviourTree::ExecuteResult::FAILURE;
    }
    blackboard->food->decreaseFoodPoints(1);
    blackboard->animal->decreaseHunger(1);

    if(blackboard->food->getFoodPoints() == 0)
    {
        blackboard->food->setAsOccupied(false);
        blackboard->food = std::shared_ptr<Plant>();
        return BehaviourTree::ExecuteResult::SUCCESS;
    }
    return BehaviourTree::ExecuteResult::RUNNING;
}
