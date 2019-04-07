#ifndef GENERALPOSITIONCOMPONENT_H
#define GENERALPOSITIONCOMPONENT_H

#include "ECS/Components/positioncomponent.h"

class GeneralPositionComponent: public IPositionComponent
{
public:
    ~GeneralPositionComponent() = default;
    Position getPosition() const override { return mPosition; }
    void setPosition(const Position& pos) override { mPosition = pos; }

private:
    Position mPosition;
};

#endif // GENERALPOSITIONCOMPONENT_H
