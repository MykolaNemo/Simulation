#ifndef VELOCITYCOMPONENT_H
#define VELOCITYCOMPONENT_H

#include "../component.h"

class IVelocityComponent: public IComponent
{
public:
    virtual ~IVelocityComponent() = default;
    virtual double getVelocity() const = 0;
};

#endif // VELOCITYCOMPONENT_H
