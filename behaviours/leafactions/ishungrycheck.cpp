#include "ishungrycheck.h"

#include "models/animal/sheep.h"
#include <iostream>

IsHungryCheck::IsHungryCheck(std::shared_ptr<Sheep> sheep, BehaviourTree *parent)
    : IsHungryCheck("", sheep, parent){}

IsHungryCheck::IsHungryCheck(std::string name, std::shared_ptr<Sheep> sheep, BehaviourTree *parent)
    : BehaviourTree(std::move(name), parent)
    , mSheep(std::move(sheep))
{

}

BehaviourTree::ExecuteResult IsHungryCheck::execute(const std::chrono::milliseconds &)
{
    if(!mSheep)
    {
        return BehaviourTree::ExecuteResult::FAILURE;
    }
    return (mSheep->getHunger() >= mSheep->getHungerThreshold())
            ? BehaviourTree::ExecuteResult::SUCCESS
            : BehaviourTree::ExecuteResult::FAILURE;
}
