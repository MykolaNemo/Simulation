#include "plant.h"
#include "state/plantstates/plantstategrowing.h"

#include <iostream>
#include <QElapsedTimer>

QElapsedTimer t2;

Plant::Plant(const Position& pos):
    FieldObject(pos)
{
    m_state = std::make_shared<PlantStateGrowing>();
}

void Plant::update(const Field &field)
{
    t2.start();
    if(!m_state) return;

    auto ptr(shared_from_this());
    std::shared_ptr<StateAbstract> nextState = m_state->update(ptr, field);
    if(nextState)
    {
        m_state = nextState;
    }
    std::cout<<"Plant update: "<<t2.elapsed()<<std::endl;
}

void Plant::setState(const std::shared_ptr<PlantState> &newState)
{
    if(newState)
    {
        m_state = newState;
    }
}
