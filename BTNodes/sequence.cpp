#include "sequence.h"

#include <algorithm>
//#include <iostream>

Sequence::Sequence(BehaviourTree *parent)
    : Sequence("", parent)
{
}

Sequence::Sequence(std::string name, BehaviourTree *parent)
    : BehaviourTree(std::move(name),parent)
{
}

BehaviourTree *Sequence::addChild(BehaviourTree *child)
{
    mChildren.push_back(child);
    return this;
}

void Sequence::removeChild(BehaviourTree *child)
{
    mChildren.erase(std::remove(mChildren.begin(), mChildren.end(), child), mChildren.end());
}

std::vector<BehaviourTree *> Sequence::getChildren() const
{
    return mChildren;
}

BehaviourTree::ExecuteResult Sequence::execute(const std::chrono::milliseconds &tick, std::shared_ptr<Blackboard> &blackboard)
{
    for(BehaviourTree* child : mChildren)
    {
        ExecuteResult result = child->execute(tick, blackboard);
        switch (result) {
        case ExecuteResult::FAILURE:
            return ExecuteResult::FAILURE;
        case ExecuteResult::RUNNING:
            return ExecuteResult::RUNNING;
        case ExecuteResult::SUCCESS:
            continue;
        }
    }
    return ExecuteResult::SUCCESS;
}
