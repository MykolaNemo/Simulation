#include "behaviourtree.h"

BehaviourTree::BehaviourTree(int value, std::string name, BehaviourTree *parent)
    : mValue(value)
    , mName(std::move(name))
    , mParent(parent)
{

}

void BehaviourTree::setValue(int value)
{
    mValue = value;
}

int BehaviourTree::getValue() const
{
    return mValue;
}

std::string BehaviourTree::getName() const
{
    return mName;
}

BehaviourTree *BehaviourTree::getParent() const
{
    return mParent;
}
