#include "sequence.h"

#include <algorithm>
#include <iostream>
#include <string>

Sequence::Sequence(BehaviourTree *parent)
    : Sequence(0,"",parent)
{
}

Sequence::Sequence(std::string name, BehaviourTree *parent)
    : Sequence(0,std::move(name),parent)
{
}

Sequence::Sequence(int value, std::string name, BehaviourTree *parent)
    : BehaviourTree(value, std::move(name), parent)
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

BehaviourTree::ExecuteResult Sequence::execute(const std::chrono::milliseconds &tick, std::shared_ptr<Sheep> &sheep)
{
    std::cout<<getName()<<std::endl;
    for(BehaviourTree* child : mChildren)
    {
        if(!child) continue;
        ExecuteResult result = child->execute(tick, sheep);
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
