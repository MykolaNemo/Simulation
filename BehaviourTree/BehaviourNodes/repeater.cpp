#include "repeater.h"
#include <iostream>
#include <string>
#include <thread>

Repeater::Repeater(BehaviourTree *parent):
    Repeater(0,"",parent)
{

}

Repeater::Repeater(std::string name, BehaviourTree *parent)
    : Repeater(0,std::move(name),parent)
{
}

Repeater::Repeater(int value, std::string name, BehaviourTree *parent)
    : BehaviourTree(value, std::move(name), parent),
      mInterrupt(false)
{
}

Repeater::~Repeater()
{
    mInterrupt.store(true);
    mThread->join();
}

BehaviourTree::ExecuteResult Repeater::execute()
{
    if(!mThread)
    {
        mThread = new std::thread(&Repeater::executeAsync, this);
    }
    return ExecuteResult::RUNNING;
}

void Repeater::executeAsync()
{
    std::cout<<getName()<<std::endl;
    while((mRepeatCount > 0 || mRepeatCount == -1) && !mChildren.empty() && !mInterrupt.load())
    {
        mChildren.front()->execute();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
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
