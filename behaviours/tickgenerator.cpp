#include "tickgenerator.h"

TickGenerator::TickGenerator():
    mInterrupt(false)
{

}

TickGenerator::~TickGenerator()
{
    if(mThread)
    {
        stop();
        mThread->join();
    }
}

void TickGenerator::start(const std::vector<std::shared_ptr<Blackboard> > &blackboards)
{
    if(!mThread)
    {
        mThread = std::make_unique<std::thread>(&TickGenerator::mainLoop, this, blackboards);
    }
}

void TickGenerator::stop()
{
    mInterrupt.store(true);
}

void TickGenerator::addTree(std::shared_ptr<BehaviourTree> tree)
{
    mTreesList.push_back(tree);
}

void TickGenerator::mainLoop(const std::vector<std::shared_ptr<Blackboard> > &blackboards)
{
    auto time = std::chrono::system_clock::now();
    while(!mInterrupt.load())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        auto now = std::chrono::system_clock::now();
        auto tickDuration = std::chrono::duration_cast<std::chrono::milliseconds>(now - time);
        for(auto blackboardIt : blackboards)
        {
            for(auto tree : mTreesList)
            {
                tree->execute(tickDuration);
            }
        }
        time = now;
    }
}
