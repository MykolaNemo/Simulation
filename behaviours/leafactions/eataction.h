#ifndef EATACTION_H
#define EATACTION_H

#include "../behaviourtree.h"

#include <memory>

class Sheep;

class EatAction : public BehaviourTree
{
public:
    explicit EatAction(std::shared_ptr<Sheep> sheep,
                       BehaviourTree* parent = nullptr);
    explicit EatAction(std::string name,
                       std::shared_ptr<Sheep> sheep = std::shared_ptr<Sheep>(),
                       BehaviourTree* parent = nullptr);

    BehaviourTree* addChild(BehaviourTree *) override {return this;}
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
