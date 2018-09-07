#include "plant.h"
#include "state/plantstates/plantstategrowing.h"

Plant::Plant(const Position& pos):
    FieldObject(pos)
{
    m_state = std::make_shared<PlantStateGrowing>();
}

void Plant::update(const Field &field)
{
    if(!m_state) return;

    std::shared_ptr<StateAbstract> nextState = m_state->update(*this, field);
    if(nextState)
    {
        m_state = nextState;
        m_state->update(*this, field);
    }
}

void Plant::setState(const std::shared_ptr<PlantState> &newState)
{
    if(newState)
    {
        m_state = newState;
    }
}
