#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

#include "position.h"
#include "ECS/component.h"

class IPositionComponent: public IComponent
{
public:
    virtual ~IPositionComponent() = default;
    virtual Position getPosition() const = 0;
    virtual void setPosition(const Position& pos) = 0;
};

#endif // POSITIONCOMPONENT_H
