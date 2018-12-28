#include "tickgenerator.h"

TickGenerator::TickGenerator():
    mInterrupt(false)
{

}

TickGenerator::~TickGenerator()
{
    stop();
    mThread->join();
}

void TickGenerator::start()
{
    if(!mThread)
    {
        mThread = std::make_unique<std::thread>(&TickGenerator::mainLoop, this);
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

void TickGenerator::mainLoop()
{
    auto time = std::chrono::system_clock::now();
    while(!mInterrupt.load())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        auto now = std::chrono::system_clock::now();
        auto tickDuration = std::chrono::duration_cast<std::chrono::milliseconds>(now - time);
        for(auto tree : mTreesList)
        {
            tree->execute(tickDuration);
        }
        time = now;
    }
}
