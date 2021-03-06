#ifndef ANIMAL_H
#define ANIMAL_H

#include "models/fieldobject.h"

class Animal : public FieldObject
{
public:
    void grow();

    int getHunger() const;
    void increaseHunger(int amount);
    void decreaseHunger(int amount);
    virtual int getHungerThreshold() const;

protected:
    Animal();

private:
    int m_age = 0;//days
};

#endif // ANIMAL_H
