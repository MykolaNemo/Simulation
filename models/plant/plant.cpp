#include "plant.h"
#include "state/plantstates/plantstategrowing.h"

Plant::Plant(const Position& pos):
    FieldObject(pos)
{
    std::shared_ptr<PlantStateGrowing> plantState = std::make_shared<PlantStateGrowing>();
    createStateConnections(plantState);
    m_state = plantState;
}

void Plant::createStateConnections(const std::shared_ptr<PlantState> &plantState)
{
    if(!plantState) return;

//    plantState->nextStateRequest.connect([plantState,this](){
//        nextTaskRequest(shared_from_this());
//    });
}

void Plant::update()
{
    if(!m_state) return;

    std::shared_ptr<StateAbstract> nextState = m_state->update();
    if(nextState)
    {
        m_state = nextState;
        m_state->update();
    }
}

void Plant::setState(const std::shared_ptr<PlantState> &newState)
{
    if(newState)
    {
        m_state = newState;
    }
}
