#include "behaviourtree.h"

BehaviourTree::BehaviourTree(std::string name, BehaviourTree *parent)
    : mName(std::move(name))
    , mParent(parent)
{

}

std::string BehaviourTree::getName() const
{
    return mName;
}

BehaviourTree *BehaviourTree::getParent() const
{
    return mParent;
}
