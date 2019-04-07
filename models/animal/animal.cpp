#include "animal.h"
#include "ECS/Components/graphicscomponent.h"
#include "ECS/Components/hungercomponent.h"
#include "components/animalmovingcomponent.h"
#include "components/animalhungercomponent.h"

Animal::Animal(const Position& _position):
    FieldObject(_position)
{
    auto movingComp = std::make_shared<AnimalMovingComponent>();
    movingComp->setPosition(_position);
    addComponent(movingComp);

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

void Animal::grow()
{
    m_age++;
}
