#include "ishungrycheck.h"

#include "models/animal/sheep.h"
#include "behaviours/blackboards/blackboard.h"
//#include <iostream>

IsHungry::IsHungry(std::string name, BehaviourTree *parent)
    : BehaviourTree(std::move(name), parent)
{

}

BehaviourTree::ExecuteResult IsHungry::execute(const std::chrono::milliseconds &,
                                                    std::shared_ptr<Blackboard>& blackboard)
{
    if(!blackboard->animal)
    {
        return BehaviourTree::ExecuteResult::FAILURE;
    }
    if(blackboard->animal->getHunger() >= blackboard->animal->getHungerThreshold())
    {
        return BehaviourTree::ExecuteResult::SUCCESS;
    }
    else
    {
        return BehaviourTree::ExecuteResult::FAILURE;
    }
}
