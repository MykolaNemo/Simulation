#include "sequence.h"

#include <algorithm>
#include <iostream>
#include <string>

Sequence::Sequence(BehaviourTree *parent)
    : Sequence("", parent)
{
}

Sequence::Sequence(std::string name, BehaviourTree *parent)
    : BehaviourTree(std::move(name),parent)
{
}

void Sequence::addChild(BehaviourTree *child)
{
    mChildren.push_back(child);
}

void Sequence::removeChild(BehaviourTree *child)
{
    mChildren.erase(std::remove(mChildren.begin(), mChildren.end(), child), mChildren.end());
}

std::vector<BehaviourTree *> Sequence::getChildren() const
{
    return mChildren;
}

BehaviourTree::ExecuteResult Sequence::execute(const std::chrono::milliseconds &tick)
{
    std::cout<<getName()<<std::endl;
    for(BehaviourTree* child : mChildren)
    {
        if(!child) continue;
        ExecuteResult result = child->execute(tick);
        switch (result) {
        case ExecuteResult::FAILURE:
            return ExecuteResult::FAILURE;
        case ExecuteResult::RUNNING:
            return ExecuteResult::RUNNING;
        case ExecuteResult::SUCCESS:
            break;
        }
    }
    return ExecuteResult::SUCCESS;
}
