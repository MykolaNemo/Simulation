#ifndef EATACTION_H
#define EATACTION_H

#include "BehaviourNodes/behaviourtree.h"

#include <memory>

class Sheep;

class EatFoodAction : public BehaviourTree
{
public:
    explicit EatFoodAction(std::shared_ptr<Sheep> &sheep, BehaviourTree* parent = nullptr);
    explicit EatFoodAction(std::string name, std::shared_ptr<Sheep> &sheep, BehaviourTree* parent = nullptr);

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

#endif // EATACTION_H
