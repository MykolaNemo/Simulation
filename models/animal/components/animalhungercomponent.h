#ifndef ANIMALHUNGERCOMPONENT_H
#define ANIMALHUNGERCOMPONENT_H

#include "ECS/Components/hungercomponent.h"

class AnimalHungerComponent: public IHungerComponent
{
public:
    ~AnimalHungerComponent() = default;
    int getHungerCurrent() const override { return mCurrentHunger; }
    void increaseHunger(int amount) override { mCurrentHunger += amount; }
    void decreaseHunger(int amount) override { if(mCurrentHunger > 0){mCurrentHunger -= amount;} }
    int getHungerMaximum() const override { return mHungerMaximum; }

private:
    int mCurrentHunger = 0;
    static const int mHungerMaximum = 100;
};

#endif // ANIMALHUNGERCOMPONENT_H
