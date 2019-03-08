#include "food.h"

void Food::setFoodPoints(int foodPoints)
{
    if(foodPoints < 0)
    {
        mFoodPoints = 0;
    }
    else
    {
        mFoodPoints = foodPoints;
        /*emit*/foodPointsChanged(shared_from_this());
    }
}

int Food::getMaxFoodPoints() const
{
    return mMaxFoodPoints;
}

int Food::getFoodPoints() const
{
    return mFoodPoints;
}

void Food::decreaseFoodPoints(int points)
{
    mFoodPoints -= points;
    /*emit*/foodPointsChanged(shared_from_this());
}

void Food::increaseFoodPoints(int points)
{
    mFoodPoints += points;
    /*emit*/foodPointsChanged(shared_from_this());
}

bool Food::isOccupied() const
{
    return mIsOccupied;
}

void Food::setAsOccupied(bool occupied)
{
    mIsOccupied = occupied;
    if(mIsOccupied)
    {
        /*emit*/ wasOccupied();
    }
}
