#ifndef MOVINGCOMPONENT_H
#define MOVINGCOMPONENT_H

#include "../component.h"
#include "position.h"

class IMovingComponent: public IComponent
{
public:
    virtual ~IMovingComponent() = default;
    virtual double getVelocity() const = 0;
    virtual Position getPosition() const = 0;
    virtual void setPosition(const Position& pos) = 0;
};

#endif // MOVEINGCOMPONENT_H
