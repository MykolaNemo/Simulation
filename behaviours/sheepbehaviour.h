#ifndef SHEEPBEHAVIOUR_H
#define SHEEPBEHAVIOUR_H

#include <memory>
#include <vector>
#include <chrono>

class BehaviourTree;
class Sheep;
struct SheepBlackboard;

class SheepBehaviour
{
public:
    SheepBehaviour();
    void update(const std::chrono::milliseconds &tick, std::shared_ptr<SheepBlackboard> &blackboard);

private:
    BehaviourTree* mRoot;
};

#endif // SHEEPBEHAVIOUR_H
