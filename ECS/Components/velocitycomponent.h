#ifndef VELOCITYCOMPONENT_H
#define VELOCITYCOMPONENT_H

#include "../component.h"

class VelocityComponent: public IComponent
{
public:
    double getVelocity() const { return mVelocity; }
    void setVelocity(double velocity) { mVelocity = velocity; }

private:
    double mVelocity = 5.0;
};

#endif // VELOCITYCOMPONENT_H
