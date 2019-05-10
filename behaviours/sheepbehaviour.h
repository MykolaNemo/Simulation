#ifndef SHEEPBEHAVIOUR_H
#define SHEEPBEHAVIOUR_H

#include <memory>
#include <chrono>
#include "BTNodes/behaviourtree.h"
#include "behaviour.h"

struct Blackboard;
class SheepBehaviour: public IBehaviour
{
public:
    SheepBehaviour();
    ~SheepBehaviour() override = default;
    void update(const std::chrono::milliseconds &tick, std::shared_ptr<Blackboard>& blackboard) override;

private:
    std::unique_ptr<BehaviourTree> mRoot;
};

#endif // SHEEPBEHAVIOUR_H
