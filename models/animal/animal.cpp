#include "animal.h"
#include "ECS/Components/graphicscomponent.h"
#include "ECS/Components/hungercomponent.h"
#include "components/animalvelocitycomponent.h"
#include "components/generalpositioncomponent.h"
#include "components/animalhungercomponent.h"

Animal::Animal(const Position& _position):
    FieldObject(_position)
{
    auto velocityComp = std::make_shared<AnimalVelocityComponent>();
    addComponent(velocityComp);

    auto hungerComp = std::make_shared<AnimalHungerComponent>();
    addComponent(hungerComp);
}

int Animal::getHunger() const
{
    return getComponent<AnimalHungerComponent>()->getHungerCurrent();
}

void Animal::increaseHunger(int amount)
{
    getComponent<AnimalHungerComponent>()->increaseHunger(amount);
}

void Animal::decreaseHunger(int amount)
{
    getComponent<AnimalHungerComponent>()->decreaseHunger(amount);
}

int Animal::getHungerThreshold() const
{
    return getComponent<AnimalHungerComponent>()->getHungerMaximum();
}

void Animal::grow()
{
    m_age++;
}
