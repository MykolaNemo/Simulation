#ifndef NEARFOODCHECK_H
#define NEARFOODCHECK_H

#include "BTNodes/behaviourtree.h"

class NearFoodCheck: public BehaviourTree
{
public:
    explicit NearFoodCheck(std::string name, BehaviourTree* parent = nullptr);

    BehaviourTree* addChild(BehaviourTree *) override {return this;}
    void removeChild(BehaviourTree *) override {}
    std::vector<BehaviourTree *> getChildren() const override
    {
        return std::vector<BehaviourTree *>();
    }
    ExecuteResult execute(const std::chrono::milliseconds &, std::shared_ptr<Blackboard> &blackboard) override;
};

#endif // NEARFOODCHECK_H
