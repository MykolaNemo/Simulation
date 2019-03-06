#include "animal.h"
#include "state/state.h"
#include "state/animalstates/animalstateidle.h"
#include "state/animalstates/animalstatewalking.h"
#include "state/animalstates/animalstateeating.h"

#include <iostream>
#include <memory>

Animal::Animal(const Position& _position):
    FieldObject(_position)
{
    auto animalState = std::make_shared<AnimalStateIdle>();
    m_state = animalState;
}

//void Animal::update(const Field &field, const std::chrono::milliseconds &tick)
//{
//    if(!m_state) return;

//    hunger++;
//    auto ptr(shared_from_this());
//    std::shared_ptr<StateAbstract> nextState = m_state->update(ptr, field);
//    if(nextState)
//    {
//        m_state = nextState;
//    }
//}

void Animal::setState(const std::shared_ptr<AnimalState> &newState)
{
    if(newState)
    {
        m_state = newState;
    }
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
