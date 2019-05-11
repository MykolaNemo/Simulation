#ifndef GOTOFOODACTION_H
#define GOTOFOODACTION_H

#include "../behaviourtree.h"
#include "position.h"
#include <map>

class IEntity;

class GoToFood: public BehaviourTree
{
public:
    explicit GoToFood(std::string name, BehaviourTree* parent = nullptr);

    BehaviourTree* addChild(BehaviourTree *) override {return this;}
    void removeChild(BehaviourTree *) override {}
    std::vector<BehaviourTree *> getChildren() const override
    {
        return std::vector<BehaviourTree *>();
    }
    ExecuteResult execute(const std::chrono::milliseconds &tick, std::shared_ptr<Blackboard> &blackboard) override;

private:
    struct Data
    {
        double distanceWalked = 0.0;
        double totalDistance = 0.0;
        Position startPoint;
        Position destinationPoint;
    };
    std::map<std::shared_ptr<IEntity>, Data> mDataMap;
};

#endif // GOTOFOODACTION_H
