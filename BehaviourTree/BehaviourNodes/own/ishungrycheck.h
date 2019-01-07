#ifndef ISHUNGRYCHECK_H
#define ISHUNGRYCHECK_H

#include "BehaviourNodes/behaviourtree.h"
#include <memory>

class Sheep;

class IsHungryCheck : public BehaviourTree
{
public:
    explicit IsHungryCheck(std::shared_ptr<Sheep> &sheep, BehaviourTree* parent = nullptr);
    explicit IsHungryCheck(std::string name, std::shared_ptr<Sheep> &sheep, BehaviourTree* parent = nullptr);

    // BehaviourTree interface
public:
    void addChild(BehaviourTree *) override {}
    void removeChild(BehaviourTree *) override {}
    std::vector<BehaviourTree *> getChildren() const override
    {
        return std::vector<BehaviourTree *>();
    }
    ExecuteResult execute(const std::chrono::milliseconds &) override;

private:
    std::shared_ptr<Sheep> mSheep;
};

#endif // ISHUNGRYCHECK_H
