#ifndef SELECTOR_H
#define SELECTOR_H

#include "behaviourtree.h"

class Fallback: public BehaviourTree
{
public:
    explicit Fallback(BehaviourTree* parent = nullptr);
    explicit Fallback(std::string name, BehaviourTree* parent = nullptr);
    explicit Fallback(int value, std::string name = "", BehaviourTree* parent = nullptr);
    void addChild(BehaviourTree* child) override;
    void removeChild(BehaviourTree* child) override;
    std::vector<BehaviourTree*> getChildren() const override;
    ExecuteResult execute(const std::chrono::milliseconds& tick) override;

private:
    std::vector<BehaviourTree*> mChildren;
};

#endif // SELECTOR_H
