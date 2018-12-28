#include "invertor.h"

Invertor::Invertor(BehaviourTree *parent):
    Invertor(0, "", parent)
{

}

Invertor::Invertor(std::string name, BehaviourTree *parent):
    Invertor(0, std::move(name), parent)
{

}

Invertor::Invertor(int value, std::string name, BehaviourTree *parent):
    BehaviourTree(value, std::move(name), parent)
{

}

BehaviourTree::ExecuteResult Invertor::execute(const std::chrono::milliseconds &tick)
{
    if(!mChildren.empty())
    {
        ExecuteResult result = mChildren.front()->execute(tick);
        switch(result)
        {
        case ExecuteResult::SUCCESS:
        {
            return ExecuteResult::FAILURE;
        }
        case ExecuteResult::FAILURE:
        {
            return ExecuteResult::SUCCESS;
        }
        case ExecuteResult::RUNNING:
        {
            return ExecuteResult::RUNNING;
        }
        }
    }
    return ExecuteResult::FAILURE;
}

void Invertor::addChild(BehaviourTree *child)
{
    if(mChildren.empty())
    {
        mChildren.push_back(child);
    }
}

void Invertor::removeChild(BehaviourTree *child)
{
    if(mChildren.front() == child)
    {
        mChildren.erase(mChildren.begin());
    }
}

std::vector<BehaviourTree *> Invertor::getChildren() const
{
    return mChildren;
}
