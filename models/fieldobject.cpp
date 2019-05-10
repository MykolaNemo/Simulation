#include "fieldobject.h"
#include "models/animal/components/generalpositioncomponent.h"

#include <iostream>

FieldObject::FieldObject(const Position &_position):
    IEntity()
{
    auto positionComp = std::make_shared<GeneralPositionComponent>();
    positionComp->setPosition(_position);
    addComponent(positionComp);
}

Position FieldObject::getPosition() const
{
    return getComponent<GeneralPositionComponent>()->getPosition();
}

void FieldObject::setPosition(const int x, const int y)
{
    Position oldPos = getComponent<GeneralPositionComponent>()->getPosition();
    if((oldPos.x == x) && (oldPos.y == y))
    {
        return;
    }
    const Position newPos(x,y);
    getComponent<GeneralPositionComponent>()->setPosition(newPos);
    positionChanged(std::static_pointer_cast<FieldObject>(shared_from_this()), newPos);
}
