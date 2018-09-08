#include "animal.h"
#include "state/animalstates/animalstateidle.h"
#include "state/animalstates/animalstatewalking.h"
#include "state/animalstates/animalstateeating.h"

#include <iostream>
#include <memory>
#include <QElapsedTimer>

QElapsedTimer t;

Animal::Animal(const Position& _position):
    FieldObject(_position)
{
    auto animalState = std::make_shared<AnimalStateIdle>();
    m_state = animalState;
}

void Animal::update(const Field &field)
{
    t.start();
    if(!m_state) return;

    auto ptr(shared_from_this());
    std::shared_ptr<StateAbstract> nextState = m_state->update(ptr, field);
    if(nextState)
    {
        m_state = nextState;
    }
//    std::cout<<"Animal update: "<<t.elapsed()<<std::endl;
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
