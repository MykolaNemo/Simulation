#ifndef IDLEACTION_H
#define IDLEACTION_H

#include "../behaviourtree.h"

#include <memory>

class Animal;
//class Food;

class IdleAction : public BehaviourTree
{
public:
    IdleAction(std::string name, BehaviourTree* parent = nullptr);

    BehaviourTree* addChild(BehaviourTree *) override {return this;}
    void removeChild(BehaviourTree *) override {}
    std::vector<BehaviourTree *> getChildren() const override
    {
        return std::vector<BehaviourTree *>();
    }
    ExecuteResult execute(const std::chrono::milliseconds &, std::shared_ptr<Blackboard> &blackboard) override;

private:
    std::shared_ptr<Animal> mAnimal;
//    std::shared_ptr<Food> mFood;
};

#endif // IDLEACTION_H
