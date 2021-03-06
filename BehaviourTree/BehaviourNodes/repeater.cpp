#include "repeater.h"
#include <iostream>
#include <string>
#include <thread>

Repeater::Repeater(BehaviourTree *parent):
    Repeater("", parent)
{

}

Repeater::Repeater(std::string name, BehaviourTree *parent)
    : BehaviourTree(std::move(name), parent)
{
}

Repeater::~Repeater()
{
    mInterrupt.store(true);
    mThread->join();
}

BehaviourTree::ExecuteResult Repeater::execute(const std::chrono::milliseconds &)
{
    if(!mThread)
    {
        mThread = std::make_shared<std::thread>(&Repeater::executeAsync, this);
    }
    return ExecuteResult::RUNNING;
}

void Repeater::executeAsync()
{
    std::cout<<getName()<<std::endl;
//    while((mRepeatCount > 0 || mRepeatCount == -1) && !mChildren.empty() && !mInterrupt.load())
//    {
//        mChildren.front()->execute();
//        std::this_thread::sleep_for(std::chrono::milliseconds(50));
//    }
}

void Repeater::addChild(BehaviourTree *child)
{
    if(mChildren.empty() && child)
    {
        mChildren.push_back(child);
    }
}

void Repeater::removeChild(BehaviourTree *child)
{
    if(mChildren.front() == child)
    {
        mChildren.erase(mChildren.begin());
    }
}

std::vector<BehaviourTree *> Repeater::getChildren() const
{
    return std::vector<BehaviourTree*>();
}
