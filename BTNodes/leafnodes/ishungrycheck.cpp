#include "ishungrycheck.h"

#include "models/animal/sheep.h"
#include "behaviours/blackboards/blackboard.h"
//#include <iostream>

IsHungryCheck::IsHungryCheck(std::string name, BehaviourTree *parent)
    : BehaviourTree(std::move(name), parent)
{

}

BehaviourTree::ExecuteResult IsHungryCheck::execute(const std::chrono::milliseconds &,
                                                    std::shared_ptr<Blackboard>& blackboard)
{
//    std::cout<<getName();
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
