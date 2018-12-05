#include "invertor.h"

Invertor::Invertor(BehaviourTree *parent):
    Invertor(0, "", parent)
{

}

Invertor::Invertor(std::string name, BehaviourTree *parent):
    Invertor(0, name, parent)
{

}

Invertor::Invertor(int value, std::string name, BehaviourTree *parent):
    BehaviourTree(value, name, parent)
{

}

BehaviourTree::ExecuteResult Invertor::execute()
{
    if(!mChildren.empty())
    {
        ExecuteResult result = mChildren.front()->execute();
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
    if(mChildren.size() == 0)
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
