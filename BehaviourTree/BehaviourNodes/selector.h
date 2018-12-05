#ifndef SELECTOR_H
#define SELECTOR_H

#include "behaviourtree.h"

class Selector: public BehaviourTree
{
public:
    explicit Selector(BehaviourTree* parent = nullptr);
    explicit Selector(std::string name, BehaviourTree* parent = nullptr);
    explicit Selector(int value, std::string name = "", BehaviourTree* parent = nullptr);
    void addChild(BehaviourTree* child) override;
    void removeChild(BehaviourTree* child) override;
    std::vector<BehaviourTree*> getChildren() const override;
    ExecuteResult execute() override;

private:
    std::vector<BehaviourTree*> mChildren;
};

#endif // SELECTOR_H
