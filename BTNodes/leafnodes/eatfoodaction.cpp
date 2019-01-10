#include "eatfoodaction.h"

#include "models/animal/sheep.h"
#include <iostream>

EatFoodAction::EatFoodAction(std::string name, BehaviourTree *parent)
    : BehaviourTree(std::move(name), parent)
{

}

BehaviourTree::ExecuteResult EatFoodAction::execute(const std::chrono::milliseconds &,
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
