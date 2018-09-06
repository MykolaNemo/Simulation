#ifndef SIMCORE_H
#define SIMCORE_H

#include <memory>
#include <future>
#include <atomic>
#include "signal.h"

class Field;
class ThinkerInfo;
class SimCore
{
public:
    SimCore(const std::shared_ptr<Field>& field);
    ~SimCore();
    SimCore(const SimCore&) = default;
    SimCore(SimCore&&) = default;
    SimCore& operator=(const SimCore&) = default;
    SimCore& operator=(SimCore&&) = default;
    void start();
    void join();

private:
    void mainLoop();
    void dummySlot();

private:
    std::future<void> m_future;
    std::shared_ptr<Field> field;
    std::atomic_bool m_interrupt = {false};
};

#endif // SIMCORE_H
