#ifndef FOODCOMPONENT_H
#define FOODCOMPONENT_H

#include "../component.h"

class FoodComponent: public IComponent
{
public:
    void increaseAmount(int amount)
    {
        int newValue = mAmount + amount;
        if(newValue > mMaxAmount)
        {
            newValue = mMaxAmount;
        }
        mAmount = newValue;
    }

    void decreaseAmount(int amount)
    {
        int newValue = mAmount - amount;
        if(newValue < 0)
        {
            newValue = 0;
        }
        mAmount = newValue;
    }

    int getCurrentAmount() const
    {
        return mAmount;
    }

    int getMaximumAmount() const
    {
        return mMaxAmount;
    }

private:
    int mMaxAmount = 250;
    int mAmount = mMaxAmount;
};

#endif // FOODCOMPONENT_H
