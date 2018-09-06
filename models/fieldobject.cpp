#include "fieldobject.h"

#include <iostream>
#include "state/state.h"

FieldObject::FieldObject(const Position &_position):
    m_position(_position)
{
}

FieldObject::~FieldObject()
{
}

Position FieldObject::getPosition() const
{
    return m_position;
}

void FieldObject::setPosition(const int x, const int y)
{
    if((m_position.x == x) && (m_position.y == y))
    {
        return;
    }
    m_position.x = x;
    m_position.y = y;
    positionChanged(shared_from_this(), m_position);
}

void FieldObject::setPosition(const Position &pos)
{
    if(m_position == pos)
    {
        return;
    }
    m_position = pos;
    positionChanged(shared_from_this(), m_position);
}
