#ifndef EATFOODACTION_H
#define EATFOODACTION_H

#include "../behaviourtree.h"
#include <memory>

class EatFood : public BehaviourTree
{
public:
    EatFood(std::string name, BehaviourTree* parent = nullptr);

    BehaviourTree* addChild(BehaviourTree *) override {return this;}
    void removeChild(BehaviourTree *) override {}
    std::vector<BehaviourTree *> getChildren() const override
    {
        return std::vector<BehaviourTree *>();
    }
    ExecuteResult execute(const std::chrono::milliseconds &,
                          std::shared_ptr<Blackboard> &blackboard) override;
};

#endif // EATFOODACTION_H
