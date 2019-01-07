#include "eataction.h"

#include "sheep.h"
#include <iostream>

EatAction::EatAction(std::shared_ptr<Sheep> &sheep, BehaviourTree *parent)
    : EatAction("", sheep, parent){}

EatAction::EatAction(std::string name, std::shared_ptr<Sheep> &sheep, BehaviourTree *parent)
    : BehaviourTree(std::move(name), parent)
    , mSheep(sheep)
{

}

BehaviourTree::ExecuteResult EatAction::execute(const std::chrono::milliseconds &)
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
