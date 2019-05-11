#ifndef CANBEOCCUPIEDCOMPONENT_H
#define CANBEOCCUPIEDCOMPONENT_H

#include "../component.h"

class CanBeOccupiedComponent : public IComponent
{
public:
    bool isOccupied() const
    {
        return mOccupied;
    }

    void setAsOccupied(bool occupied)
    {
        mOccupied = occupied;
    }

private:
    bool mOccupied = false;
};

#endif // CANBEOCCUPIEDCOMPONENT_H




