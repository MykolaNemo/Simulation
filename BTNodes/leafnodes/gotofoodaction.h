#ifndef GOTOFOODACTION_H
#define GOTOFOODACTION_H

#include "../behaviourtree.h"

class GoToFoodAction: public BehaviourTree
{
public:
    explicit GoToFoodAction(std::string name, BehaviourTree* parent = nullptr);

    BehaviourTree* addChild(BehaviourTree *) override {return this;}
    void removeChild(BehaviourTree *) override {}
    std::vector<BehaviourTree *> getChildren() const override
    {
        return std::vector<BehaviourTree *>();
    }
    ExecuteResult execute(const std::chrono::milliseconds &tick, std::shared_ptr<Blackboard> &blackboard) override;
};

#endif // GOTOFOODACTION_H
