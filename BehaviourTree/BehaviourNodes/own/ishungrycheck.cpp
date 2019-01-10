#include "ishungrycheck.h"

#include "sheep.h"
#include <iostream>

IsHungryCheck::IsHungryCheck(std::shared_ptr<Sheep> sheep, BehaviourTree *parent)
    : IsHungryCheck("", std::move(sheep), parent){}

IsHungryCheck::IsHungryCheck(std::string name, std::shared_ptr<Sheep> sheep, BehaviourTree *parent)
    : BehaviourTree(std::move(name), parent)
    , mSheep(std::move(sheep))
{

}

BehaviourTree::ExecuteResult IsHungryCheck::execute(const std::chrono::milliseconds &)
{
    std::cout<<"Is hungry?"<<std::endl;
    if(!mSheep)
    {
        return BehaviourTree::ExecuteResult::FAILURE;
    }
    return (mSheep->hungry) ? BehaviourTree::ExecuteResult::SUCCESS : BehaviourTree::ExecuteResult::FAILURE;
}
