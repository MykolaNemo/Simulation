#include "fallback.h"
#include <algorithm>
#include <iostream>
#include <string>

Fallback::Fallback(BehaviourTree *parent)
    : Fallback(0,"",parent)
{
}

Fallback::Fallback(std::string name, BehaviourTree *parent)
    : Fallback(0,std::move(name),parent)
{
}

Fallback::Fallback(int value, std::string name, BehaviourTree *parent)
    : BehaviourTree(value, std::move(name), parent)
{
}

void Fallback::addChild(BehaviourTree *child)
{
    mChildren.push_back(child);
}

void Fallback::removeChild(BehaviourTree *child)
{
    mChildren.erase(std::remove(mChildren.begin(), mChildren.end(), child), mChildren.end());
}

std::vector<BehaviourTree *> Fallback::getChildren() const
{
    return mChildren;
}

BehaviourTree::ExecuteResult Fallback::execute(const std::chrono::milliseconds &tick, std::shared_ptr<Sheep> &sheep)
{
    std::cout<<getName()<<std::endl;
    for(BehaviourTree* child : mChildren)
    {
        if(!child) continue;
        ExecuteResult result = child->execute(tick, sheep);
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
