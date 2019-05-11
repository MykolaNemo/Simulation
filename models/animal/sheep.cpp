#include "sheep.h"
#include "graphicsitems/sheepgraphicsitem.h"
#include "ECS/Components/aicomponent.h"
#include "ECS/Components/graphicscomponent.h"

#include <iostream>

const std::shared_ptr<SheepBehaviour> Sheep::mBehaviour = std::make_shared<SheepBehaviour>();

//ugly hack for shared_ptr with protected constructors
namespace {
class SheepDer:public Sheep {};
}

void Sheep::init()
{
    auto sheepGraphicsItem = new SheepGraphicsItem(std::static_pointer_cast<Sheep>(shared_from_this()));
    sheepGraphicsItem->setZValue(1);
    addComponent(std::make_shared<GraphicsComponent>(sheepGraphicsItem));
    addComponent(std::make_shared<AIComponent>(shared_from_this(), mBehaviour));
}

void Sheep::update(const std::shared_ptr<Field> &field, const std::chrono::milliseconds& tick)
{
    auto blackboard = getComponent<AIComponent>()->getBlackboard();
    mBehaviour->update(tick, blackboard);
}

QGraphicsItem *Sheep::getGraphics() const
{
    return getComponent<GraphicsComponent>()->getGraphics();
}

std::shared_ptr<Sheep> Sheep::create()
{
    auto sheep = std::make_shared<SheepDer>();
    sheep->init();
    return sheep;
}

std::shared_ptr<SheepBehaviour> Sheep::getBehaviour() const
{
    return mBehaviour;
}
