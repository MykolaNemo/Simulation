#include "idleaction.h"

//#include <iostream>
#include "models/animal/animal.h"
#include "behaviours/blackboards/blackboard.h"

IdleAction::IdleAction(std::string name, BehaviourTree *parent)
    : BehaviourTree(std::move(name), parent)
{
}

BehaviourTree::ExecuteResult IdleAction::execute(const std::chrono::milliseconds &,
                                                 std::shared_ptr<Blackboard>& blackboard)
{
//    std::cout<<getName();
    if(!blackboard->animal)
    {
//        std::cout<<": FAILURE"<<std::endl;
        return BehaviourTree::ExecuteResult::FAILURE;
    }
    blackboard->animal->increaseHunger(1);
//    std::cout<<": SUCCESS"<<std::endl;
    return BehaviourTree::ExecuteResult::SUCCESS;
}
