#include "eataction.h"

#include "sheep.h"
#include <iostream>

EatFoodAction::EatFoodAction(std::shared_ptr<Sheep> &sheep, BehaviourTree *parent)
    : EatFoodAction("", sheep, parent){}

EatFoodAction::EatFoodAction(std::string name, std::shared_ptr<Sheep> &sheep, BehaviourTree *parent)
    : BehaviourTree(std::move(name), parent)
    , mSheep(sheep)
{

}

BehaviourTree::ExecuteResult EatFoodAction::execute(const std::chrono::milliseconds &)
{
    std::cout<<"EatAction"<<std::endl;
    if(!mSheep)
    {
        return BehaviourTree::ExecuteResult::FAILURE;
    }
    if(mSheep->hungry)
    {
        mSheep->hungry = false;
        return BehaviourTree::ExecuteResult::SUCCESS;
    }
    else
    {
        return BehaviourTree::ExecuteResult::FAILURE;
    }
}
