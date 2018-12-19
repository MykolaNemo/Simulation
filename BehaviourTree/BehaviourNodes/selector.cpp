#include "selector.h"
#include <algorithm>
#include <iostream>
#include <string>

Selector::Selector(BehaviourTree *parent)
    : Selector(0,"",parent)
{
}

Selector::Selector(std::string name, BehaviourTree *parent)
    : Selector(0,std::move(name),parent)
{
}

Selector::Selector(int value, std::string name, BehaviourTree *parent)
    : BehaviourTree(value, std::move(name), parent)
{
}

void Selector::addChild(BehaviourTree *child)
{
    mChildren.push_back(child);
}

void Selector::removeChild(BehaviourTree *child)
{
    mChildren.erase(std::remove(mChildren.begin(), mChildren.end(), child), mChildren.end());
}

std::vector<BehaviourTree *> Selector::getChildren() const
{
    return mChildren;
}

BehaviourTree::ExecuteResult Selector::execute()
{
    std::cout<<getName()<<std::endl;
    for(BehaviourTree* child : mChildren)
    {
        if(!child) continue;
        ExecuteResult result = child->execute();
        switch (result) {
        case ExecuteResult::FAILURE:
            continue;
        case ExecuteResult::RUNNING:
            return ExecuteResult::RUNNING;
        case ExecuteResult::SUCCESS:
            return ExecuteResult::SUCCESS;
        }
    }
    return ExecuteResult::FAILURE;
}
