#ifndef REPEATER_H
#define REPEATER_H

#include "behaviourtree.h"
#include <atomic>

namespace std{
class thread;
}

class Repeater: public BehaviourTree
{
public:
    explicit Repeater(BehaviourTree *parent = nullptr);
    explicit Repeater(std::string name, BehaviourTree *parent = nullptr);
    ~Repeater() override;
    Repeater(const Repeater&) = default;
    Repeater(Repeater&&) = default;
    Repeater& operator=(const Repeater&) = default;
    Repeater& operator=(Repeater&&) = default;

    ExecuteResult execute(const std::chrono::milliseconds&) override;
    void executeAsync();

private:
    void addChild(BehaviourTree* child) override;
    void removeChild(BehaviourTree* child) override;
    std::vector<BehaviourTree*> getChildren() const override;

private:
    std::vector<BehaviourTree*> mChildren;
    int mRepeatCount = -1;
    std::atomic_bool mInterrupt;
    std::shared_ptr<std::thread> mThread;
};

#endif // REPEATER_H
