#ifndef SELECTOR_H
#define SELECTOR_H

#include "behaviourtree.h"

class Fallback: public BehaviourTree
{
public:
    explicit Fallback(BehaviourTree* parent = nullptr);
    explicit Fallback(std::string name, BehaviourTree* parent = nullptr);
    BehaviourTree *addChild(BehaviourTree* child) override;
    void removeChild(BehaviourTree* child) override;
    std::vector<BehaviourTree*> getChildren() const override;
    ExecuteResult execute(const std::chrono::milliseconds& tick,
                          std::shared_ptr<Blackboard> &blackboard) override;

private:
    std::vector<BehaviourTree*> mChildren;
    BehaviourTree* currentNode = nullptr;
};

#endif // SELECTOR_H
