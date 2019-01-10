#ifndef EATFOODACTION_H
#define EATFOODACTION_H

#include "../behaviourtree.h"

#include <memory>

class Animal;
class Food;

class EatFoodAction : public BehaviourTree
{
public:
    EatFoodAction(std::string name, BehaviourTree* parent = nullptr);

    BehaviourTree* addChild(BehaviourTree *) override {return this;}
    void removeChild(BehaviourTree *) override {}
    std::vector<BehaviourTree *> getChildren() const override
    {
        return std::vector<BehaviourTree *>();
    }
    ExecuteResult execute(const std::chrono::milliseconds &,
                          std::shared_ptr<Blackboard> &blackboard) override;

private:
    std::shared_ptr<Animal> mAnimal;
    std::shared_ptr<Food> mFood;
};

#endif // EATFOODACTION_H
