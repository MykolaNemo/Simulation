#ifndef ISHUNGRYCHECK_H
#define ISHUNGRYCHECK_H

#include "../behaviourtree.h"
#include <memory>

class Sheep;

class IsHungry : public BehaviourTree
{
public:
    explicit IsHungry(std::string name,
                           BehaviourTree* parent = nullptr);

    BehaviourTree* addChild(BehaviourTree *) override {return this;}
    void removeChild(BehaviourTree *) override {}
    std::vector<BehaviourTree *> getChildren() const override
    {
        return std::vector<BehaviourTree *>();
    }
    ExecuteResult execute(const std::chrono::milliseconds &, std::shared_ptr<Blackboard> &blackboard) override;
};

#endif // ISHUNGRYCHECK_H
