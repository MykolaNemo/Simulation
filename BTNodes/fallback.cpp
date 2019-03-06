#include "fallback.h"
#include <algorithm>
#include <iostream>
#include <string>

Fallback::Fallback(BehaviourTree *parent)
    : Fallback("",parent)
{
}

Fallback::Fallback(std::string name, BehaviourTree *parent)
    : BehaviourTree(std::move(name),parent)
{
}

BehaviourTree* Fallback::addChild(BehaviourTree *child)
{
    mChildren.push_back(child);
    return this;
}

void Fallback::removeChild(BehaviourTree *child)
{
    mChildren.erase(std::remove(mChildren.begin(), mChildren.end(), child), mChildren.end());
}

std::vector<BehaviourTree *> Fallback::getChildren() const
{
    return mChildren;
}

BehaviourTree::ExecuteResult Fallback::execute(const std::chrono::milliseconds &tick,
                                               std::shared_ptr<Blackboard>& blackboard)
{
    std::cout<<getName()<<std::endl;
    for(BehaviourTree* child : mChildren)
    {
        if(!child)
        {
            continue;
        }

        if(currentNode != nullptr && currentNode != child)
        {
//            continue;
        }
        currentNode = child;

        ExecuteResult result = child->execute(tick, blackboard);
        switch (result) {
        case ExecuteResult::FAILURE:
            currentNode = nullptr;
            break;
        case ExecuteResult::RUNNING:
            return ExecuteResult::RUNNING;
        case ExecuteResult::SUCCESS:
            currentNode = nullptr;
            return ExecuteResult::SUCCESS;
        }
    }
    return ExecuteResult::FAILURE;
}
