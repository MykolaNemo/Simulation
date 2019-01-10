#ifndef INVERTOR_H
#define INVERTOR_H

#include "behaviourtree.h"

class Invertor: public BehaviourTree
{
public:
    explicit Invertor(BehaviourTree *parent = nullptr);
    explicit Invertor(std::string name, BehaviourTree *parent = nullptr);
    ExecuteResult execute(const std::chrono::milliseconds& tick,
                          std::shared_ptr<Blackboard> &blackboard) override;
    BehaviourTree* addChild(BehaviourTree* child) override;
    void removeChild(BehaviourTree* child) override;
    std::vector<BehaviourTree*> getChildren() const override;

private:
    std::vector<BehaviourTree*> mChildren;
};

#endif // INVERTOR_H
