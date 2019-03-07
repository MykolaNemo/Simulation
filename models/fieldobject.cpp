#include "fieldobject.h"
#include "fieldobject.h"
#include "fieldobject.h"

#include <iostream>

FieldObject::FieldObject(const Position &_position):
    m_position(_position)
{
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

bool FieldObject::isInUse() const
{
    return mInUse;
}

void FieldObject::setInUse(bool occupied)
{
    mInUse = occupied;
    if(mInUse)
    {
        /*emit*/ wasOccupied();
    }
}
