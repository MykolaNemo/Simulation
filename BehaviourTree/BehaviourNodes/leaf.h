#ifndef LEAF_H
#define LEAF_H

#include <vector>
#include "behaviourtree.h"

class Leaf: public BehaviourTree
{
public:
    explicit Leaf(BehaviourTree *parent = nullptr);
    explicit Leaf(std::string name, BehaviourTree *parent = nullptr);
    explicit Leaf(int value, std::string name = "", BehaviourTree* parent = nullptr);
    ExecuteResult execute() override;

private:
    void addChild(BehaviourTree* child) override;
    void removeChild(BehaviourTree* child) override;
    std::vector<BehaviourTree*> getChildren() const override;
};

#endif // LEAF_H
