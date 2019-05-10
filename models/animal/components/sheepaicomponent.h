#ifndef SHEEPAICOMPONENT_H
#define SHEEPAICOMPONENT_H

#include "ECS/Components/aicomponent.h"
#include "behaviours/blackboards/blackboard.h"

class Sheep;
class SheepBehaviour;

class SheepAIComponent: public IAIComponent
{
public:
    SheepAIComponent(const std::shared_ptr<Sheep>& sheep):
        mBlackboard(std::make_shared<Blackboard>())
    {
        mBlackboard->animal = sheep;
    }
    ~SheepAIComponent() override = default;

    std::shared_ptr<IBehaviour> getBehaviour() const override {
        return std::static_pointer_cast<IBehaviour>(mBehaviour);
    }
    std::shared_ptr<Blackboard> getBlackboard() const override {
        return mBlackboard;
    }

private:
    static std::shared_ptr<SheepBehaviour> mBehaviour;
    std::shared_ptr<Blackboard> mBlackboard;
};

std::shared_ptr<SheepBehaviour> SheepAIComponent::mBehaviour = std::make_shared<SheepBehaviour>();

#endif // SHEEPAICOMPONENT_H
