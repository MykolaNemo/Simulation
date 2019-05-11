#include "ishungrycheck.h"

#include "ECS/Components/hungercomponent.h"
#include "models/animal/sheep.h"
#include "behaviours/blackboards/blackboard.h"

#include <iostream>

IsHungry::IsHungry(std::string name, BehaviourTree *parent)
    : BehaviourTree(std::move(name), parent)
{
}

BehaviourTree::ExecuteResult IsHungry::execute(const std::chrono::milliseconds &,
                                                    std::shared_ptr<Blackboard>& blackboard)
{
    std::cout<<"IsHungry?"<<std::endl;
    if(!blackboard->actor)
    {
        std::cout<<"IsHungry failure"<<std::endl;
        return BehaviourTree::ExecuteResult::FAILURE;
    }
    auto hungerComponent = blackboard->actor->getComponent<HungerComponent>();
    if(hungerComponent->getCurrentHunger() >= hungerComponent->getMaximumHunger())
    {
        std::cout<<"IsHungry success"<<std::endl;
        return BehaviourTree::ExecuteResult::SUCCESS;
    }
    else
    {
        std::cout<<"IsHungry failure 2"<<std::endl;
        return BehaviourTree::ExecuteResult::FAILURE;
    }
}
