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
