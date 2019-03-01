#include "plant.h"
#include "state/plantstates/plantstategrowing.h"

#include <iostream>

Plant::Plant(const Position& pos):
    FieldObject(pos)
{
    m_state = std::make_shared<PlantStateGrowing>();
    foodPointsChanged.connect([this](const std::shared_ptr<Food>&){
        invalidated(FieldObject::shared_from_this());
    });
}

void Plant::update(const Field &field, const std::chrono::milliseconds& /*tick*/)
{
    if(!m_state) return;

    auto ptr(FieldObject::shared_from_this());
    std::shared_ptr<StateAbstract> nextState = m_state->update(ptr, field);
    if(nextState)
    {
        m_state = nextState;
    }
}

void Plant::setState(const std::shared_ptr<PlantState> &newState)
{
    if(newState)
    {
        m_state = newState;
    }
}
