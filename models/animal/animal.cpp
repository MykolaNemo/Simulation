#include "animal.h"

Animal::Animal(const Position& _position):
    FieldObject(_position)
{
}

int Animal::getHunger() const
{
    return hunger;
}

void Animal::increaseHunger(int amount)
{
    hunger += amount;
}

void Animal::decreaseHunger(int amount)
{
    if(hunger > 0)
    {
        hunger -= amount;
    }
}

void Animal::grow()
{
    m_age++;
}
