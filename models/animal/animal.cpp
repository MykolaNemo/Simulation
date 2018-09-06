#include "animal.h"
#include "state/animalstates/animalstateidle.h"
#include "state/animalstates/animalstatewalking.h"
#include "state/animalstates/animalstateeating.h"

#include "visitors/thinkervisitor.h"

#include <iostream>
#include <memory>

Animal::Animal(const Position& _position):
    FieldObject(_position)
{
    auto animalState = std::make_shared<AnimalStateIdle>();
    m_state = animalState;
}

void Animal::update(const std::shared_ptr<Field> &field)
{
    if(!m_state) return;

    std::shared_ptr<StateAbstract> nextState = m_state->update();
    if(nextState)
    {
        m_state = nextState;
        m_state->update();
    }
}

void Animal::setState(const std::shared_ptr<AnimalState> &newState)
{
    if(newState)
    {
        m_state = newState;
    }
}

void Animal::grow()
{
    m_age++;
}
