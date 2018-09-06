#include "grass.h"
#include "visitors/thinkervisitor.h"
#include "visitors/drawervisitor.h"
#include "state/plantstates/plantstategrowing.h"
#include "state/plantstates/plantstatenotgrowing.h"

Grass::Grass(const Position& pos):
    Plant(pos)
{
}

//void Grass::think(const std::shared_ptr<ThinkerInfo>& thinkerInfo)
//{
//    thinkerInfo->setThinkingObject(std::dynamic_pointer_cast<Grass>(shared_from_this()));
//    m_state = m_state->next(thinkerInfo);
//    createStateConnections(std::dynamic_pointer_cast<PlantState>(m_state));
//    thinker->thinkFor(std::dynamic_pointer_cast<Sheep>(shared_from_this()));
//}

void Grass::draw(const std::shared_ptr<DrawerVisitor> &/*drawer*/)
{
//    drawer->drawFor(std::dynamic_pointer_cast<Grass>(shared_from_this()));
}
