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

bool FieldObject::isOccupied() const
{
    return m_occupied;
}

void FieldObject::setOccupied(bool occupied)
{
    m_occupied = occupied;
    if(m_occupied)
    {
        /*emit*/ wasOccupied();
    }
}

void FieldObject::setEated(bool eated)
{
    m_eated = eated;
    /*emit*/ invalidated(shared_from_this());
}

bool FieldObject::isEated() const
{
    return m_eated;
}
