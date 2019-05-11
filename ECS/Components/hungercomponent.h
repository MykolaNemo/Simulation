#ifndef HUNGERCOMPONENT_H
#define HUNGERCOMPONENT_H

#include "../component.h"
#include <algorithm>

class HungerComponent: public IComponent
{
public:
    virtual ~HungerComponent() = default;

    void increaseHunger(int hunger)
    {
        mCurrentHunger = std::min(mCurrentHunger + hunger, mMaximumHunger);
    }
    void decreaseHunger(int hunger)
    {
        mCurrentHunger = std::min(mCurrentHunger - hunger, 0);
    }

    int getCurrentHunger() const
    {
        return mCurrentHunger;
    }
    void setCurrentHunger(int hunger)
    {
        mCurrentHunger = std::min(hunger, mMaximumHunger);
    }

    int getMaximumHunger() const
    {
        return mMaximumHunger;
    }
    void setMaximumHunger(int hunger)
    {
        mMaximumHunger = hunger;
    }

private:
    int mCurrentHunger = 0;
    int mMaximumHunger = 100;
};

#endif // HUNGERCOMPONENT_H
