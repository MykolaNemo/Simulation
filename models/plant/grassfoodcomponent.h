#ifndef GRASSFOODCOMPONENT_H
#define GRASSFOODCOMPONENT_H

#include "ECS/Components/foodcomponent.h"

class GrassFoodComponent: public IFoodComponent
{
public:
    ~GrassFoodComponent() = default;

    void increaseAmount(int amount) override
    {
        int newValue = mAmount + amount;
        if(newValue > mMaxAmount)
        {
            newValue = mMaxAmount;
        }
        mAmount = newValue;
    }

    void decreaseAmount(int amount) override
    {
        int newValue = mAmount - amount;
        if(newValue < 0)
        {
            newValue = 0;
        }
        mAmount = newValue;
    }

    int getCurrentAmount() const override
    {
        return mAmount;
    }

    int getMaximumAmount() const override
    {
        return mMaxAmount;
    }

private:
    int mMaxAmount = 250;
    int mAmount = mMaxAmount;
};

#endif // GRASSFOODCOMPONENT_H
