#ifndef HUNGERCOMPONENT_H
#define HUNGERCOMPONENT_H

#include "../component.h"

class IHungerComponent: public IComponent
{
public:
    virtual ~IHungerComponent() = default;
    virtual void increaseHunger(int amount) = 0;
    virtual void decreaseHunger(int amount) = 0;
    virtual int getHungerCurrent() const = 0;
    virtual int getHungerMaximum() const = 0;
};

#endif // HUNGERCOMPONENT_H
