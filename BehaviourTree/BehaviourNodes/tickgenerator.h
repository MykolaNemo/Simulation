#ifndef TICKGENERATOR_H
#define TICKGENERATOR_H

#include <memory>
#include <thread>
#include <atomic>
#include <chrono>
#include "behaviourtree.h"
#include "sheep.h"

#include <memory>

class TickGenerator
{
public:
    TickGenerator(std::shared_ptr<Sheep>& sheep);
    ~TickGenerator();
    void start();
    void stop();
    void addTree(std::shared_ptr<BehaviourTree> tree);

private:
    void mainLoop();
    std::unique_ptr<std::thread> mThread;
    std::atomic_bool mInterrupt;
    std::vector<std::shared_ptr<BehaviourTree> > mTreesList;

    std::shared_ptr<Sheep> mSheep;
};

#endif // TICKGENERATOR_H
