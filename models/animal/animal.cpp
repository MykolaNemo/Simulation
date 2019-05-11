#include "animal.h"
#include "ECS/Components/graphicscomponent.h"
#include "ECS/Components/hungercomponent.h"
#include "ECS/Components/velocitycomponent.h"

Animal::Animal():
    FieldObject()
{
    auto velocityComp = std::make_shared<VelocityComponent>();
    addComponent(velocityComp);

    auto hungerComp = std::make_shared<HungerComponent>();
    addComponent(hungerComp);
}

int Animal::getHunger() const
{
    return getComponent<HungerComponent>()->getCurrentHunger();
}

void Animal::increaseHunger(int amount)
{
    getComponent<HungerComponent>()->increaseHunger(amount);
}

void Animal::decreaseHunger(int amount)
{
    getComponent<HungerComponent>()->decreaseHunger(amount);
}

int Animal::getHungerThreshold() const
{
    return getComponent<HungerComponent>()->getMaximumHunger();
}

void Animal::grow()
{
    m_age++;
}
