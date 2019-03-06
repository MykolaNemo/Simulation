#include "ishungrycheck.h"

#include "models/animal/sheep.h"
#include "behaviours/blackboards/blackboard.h"
#include <iostream>

IsHungryCheck::IsHungryCheck(std::string name, BehaviourTree *parent)
    : BehaviourTree(std::move(name), parent)
{

}

BehaviourTree::ExecuteResult IsHungryCheck::execute(const std::chrono::milliseconds &,
                                                    std::shared_ptr<Blackboard>& blackboard)
{
    std::cout<<getName();
    if(!blackboard->actor)
    {
        std::cout<<": FAILURE"<<std::endl;
        return BehaviourTree::ExecuteResult::FAILURE;
    }
    std::shared_ptr<Sheep> sheep = std::static_pointer_cast<Sheep>(blackboard->actor);
    BehaviourTree::ExecuteResult result = (sheep->getHunger() >= sheep->getHungerThreshold())
            ? BehaviourTree::ExecuteResult::SUCCESS
            : BehaviourTree::ExecuteResult::FAILURE;

    (result == BehaviourTree::ExecuteResult::SUCCESS)
            ? std::cout<<": SUCCESS"<<std::endl
            : std::cout<<": FAILURE"<<std::endl;
    return result;
}
