#ifndef SHEEPBEHAVIOUR_H
#define SHEEPBEHAVIOUR_H

#include <memory>
#include <chrono>
#include "BTNodes/behaviourtree.h"

struct Blackboard;
class SheepBehaviour
{
public:
    SheepBehaviour();
    void update(const std::chrono::milliseconds &tick, std::shared_ptr<Blackboard>& blackboard);

private:
    std::unique_ptr<BehaviourTree> mRoot;
};

#endif // SHEEPBEHAVIOUR_H
