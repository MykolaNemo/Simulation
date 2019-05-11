#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

#include "position.h"
#include "ECS/component.h"

class PositionComponent: public IComponent
{
public:
    Position getPosition() const { return mPosition; }
    void setPosition(const Position& pos) { mPosition = pos; }

private:
    Position mPosition;
};

#endif // POSITIONCOMPONENT_H
