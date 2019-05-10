#ifndef FOODCOMPONENT_H
#define FOODCOMPONENT_H

#include "../component.h"

class IFoodComponent: public IComponent
{
public:
    virtual ~IFoodComponent() = default;
    virtual void increaseAmount(int amount) = 0;
    virtual void decreaseAmount(int amount) = 0;
    virtual int getCurrentAmount() const = 0;
    virtual int getMaximumAmount() const = 0;
};

#endif // FOODCOMPONENT_H
