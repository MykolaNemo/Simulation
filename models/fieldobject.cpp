#include "fieldobject.h"
#include "fieldobject.h"
#include "fieldobject.h"

#include <iostream>
#include "state/state.h"

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

void FieldObject::setFoodPoints(const int foodPoints)
{
    if(foodPoints < 0)
    {
        mFoodPoints = 0;
    }
    else
    {
        mFoodPoints = foodPoints;
        /*emit*/ invalidated(shared_from_this());
    }
}

int FieldObject::getMaxFoodPoints() const
{
    return mMaxFoodPoints;
}

int FieldObject::getFoodPoints() const
{
    return mFoodPoints;
}
