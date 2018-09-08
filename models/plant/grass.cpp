#include "grass.h"
#include "visitors/drawervisitor.h"
#include "state/plantstates/plantstategrowing.h"
#include "state/plantstates/plantstatenotgrowing.h"

Grass::Grass(const Position& pos):
    Plant(pos)
{
}

void Grass::draw(const std::shared_ptr<DrawerVisitor> &drawer)
{
    drawer->drawFor(std::dynamic_pointer_cast<Grass>(shared_from_this()));
}
