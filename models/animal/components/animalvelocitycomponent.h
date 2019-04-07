#ifndef ANIMALMOVINGCOMPONENT_H
#define ANIMALMOVINGCOMPONENT_H

#include "ECS/Components/velocitycomponent.h"

class AnimalVelocityComponent: public IVelocityComponent
{
public:
    ~AnimalVelocityComponent() = default;
    double getVelocity() const override { return mVelocity; }

private:
    const double mVelocity = 5.0;
};

#endif // ANIMALMOVINGCOMPONENT_H
