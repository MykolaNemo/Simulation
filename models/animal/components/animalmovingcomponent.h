#ifndef ANIMALMOVINGCOMPONENT_H
#define ANIMALMOVINGCOMPONENT_H

#include "ECS/Components/movingcomponent.h"

class AnimalMovingComponent: public IMovingComponent
{
public:
    ~AnimalMovingComponent() = default;
    double getVelocity() const override { return mVelocity; }
    Position getPosition() const override { return mPosition; }
    void setPosition(const Position& pos) override { mPosition = pos; }

private:
    const double mVelocity = 5.0;
    Position mPosition;
};

#endif // ANIMALMOVINGCOMPONENT_H
