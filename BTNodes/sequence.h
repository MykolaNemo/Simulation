#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "behaviourtree.h"

class Sequence: public BehaviourTree
{
public:
    explicit Sequence(BehaviourTree* parent = nullptr);
    explicit Sequence(std::string name, BehaviourTree* parent = nullptr);
    BehaviourTree* addChild(BehaviourTree* child) override;
    void removeChild(BehaviourTree* child) override;
    std::vector<BehaviourTree*> getChildren() const override;
    ExecuteResult execute(const std::chrono::milliseconds& tick,
                          std::shared_ptr<Blackboard>& blackboard) override;

private:
    std::vector<BehaviourTree*> mChildren;
};

#endif // SEQUENCE_H
