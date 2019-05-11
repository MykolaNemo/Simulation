#include "fieldobject.h"
#include "ECS/Components/positioncomponent.h"

FieldObject::FieldObject():
    IEntity()
{
    addComponent(std::make_shared<PositionComponent>());
}

Position FieldObject::getPosition() const
{
    return getComponent<PositionComponent>()->getPosition();
}

void FieldObject::setPosition(const int x, const int y)
{
    Position oldPos = getComponent<PositionComponent>()->getPosition();
    if((oldPos.x == x) && (oldPos.y == y))
    {
        return;
    }
    const Position newPos(x,y);
    getComponent<PositionComponent>()->setPosition(newPos);
    positionChanged(std::static_pointer_cast<FieldObject>(shared_from_this()), newPos);
}
