#ifndef AICOMPONENT_H
#define AICOMPONENT_H

#include <memory>

#include "ECS/component.h"
#include "behaviours/behaviour.h"

class IAIComponent: public IComponent
{
public:
    virtual ~IAIComponent() = default;
    virtual std::shared_ptr<IBehaviour> getBehaviour() const = 0;
    virtual std::shared_ptr<Blackboard> getBlackboard() const = 0;
};

#endif // AICOMPONENT_H
