#include "idleaction.h"

#include <iostream>

IdleAction::IdleAction(std::string name, BehaviourTree *parent)
    : BehaviourTree(std::move(name), parent)
{

}

BehaviourTree::ExecuteResult IdleAction::execute(const std::chrono::milliseconds &,
                                                 std::shared_ptr<Blackboard>& blackboard)
{
    std::cout<<getName()<<std::endl;
//    std::cout<<"EatAction"<<std::endl;
//    if(!mSheep)
//    {
//        return BehaviourTree::ExecuteResult::FAILURE;
//    }
//    if(mSheep->hungry)
//    {
//        mSheep->hungry = false;
        return BehaviourTree::ExecuteResult::SUCCESS;
//    }
//    else
//    {
//        return BehaviourTree::ExecuteResult::FAILURE;
//    }
}
