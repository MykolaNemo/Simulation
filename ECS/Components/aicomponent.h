#ifndef AICOMPONENT_H
#define AICOMPONENT_H

#include <memory>

#include "ECS/component.h"
#include "behaviours/behaviour.h"
#include "behaviours/blackboards/blackboard.h"

class IEntity;
class AIComponent: public IComponent
{
public:
    AIComponent(const std::shared_ptr<IEntity>& actor, const std::shared_ptr<IBehaviour>& behaviour)
        : mBehaviour(behaviour)
        , mBlackboard(std::make_shared<Blackboard>())
    {
        mBlackboard->actor = actor;
    }

    std::shared_ptr<IBehaviour> getBehaviour() const
    {
        return mBehaviour;
    }

    std::shared_ptr<Blackboard> getBlackboard() const
    {
        return mBlackboard;
    }

private:
    const std::shared_ptr<IBehaviour> mBehaviour;
    std::shared_ptr<Blackboard> mBlackboard;
};

#endif // AICOMPONENT_H
