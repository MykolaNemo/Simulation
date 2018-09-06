#include "sheep.h"
#include "visitors/thinkervisitor.h"
#include <iostream>

Sheep::Sheep(Position pos):
    Animal(std::move(pos))
{
}

//void Sheep::think(const std::shared_ptr<ThinkerInfo>& thinkerInfo)
//{
//    thinkerInfo->setThinkingObject(std::dynamic_pointer_cast<Sheep>(shared_from_this()));
//    m_state = m_state->next(/*thinkerInfo*/);
//    createStateConnections(std::dynamic_pointer_cast<AnimalState>(m_state));
////    thinker->thinkFor(std::dynamic_pointer_cast<Sheep>(shared_from_this()));
//}

void Sheep::draw(const std::shared_ptr<DrawerVisitor> &drawer)
{
    drawer->drawFor(std::dynamic_pointer_cast<Sheep>(shared_from_this()));
}

//void Sheep::transferToNextState()
//{

//}

