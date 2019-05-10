#include "sheep.h"
#include "graphicsitems/sheepgraphicsitem.h"
#include "components/sheepgraphicscomponent.h"
#include "components/animalhungercomponent.h"
#include "components/sheepaicomponent.h"

#include <iostream>

std::shared_ptr<SheepBehaviour> Sheep::mBehaviour = std::make_shared<SheepBehaviour>();

//ugly hack for shared_ptr with protected constructors
class SheepDer:public Sheep
{
public:
    SheepDer(): Sheep(){}
};

Sheep::Sheep()
  : Animal()
  , mBlackboard(std::make_shared<Blackboard>())
{
}

void Sheep::init()
{
    addComponent(std::make_shared<SheepGraphicsComponent>(std::static_pointer_cast<Sheep>(shared_from_this())));
    addComponent(std::make_shared<SheepAIComponent>(std::static_pointer_cast<Sheep>(shared_from_this())));
    mBlackboard->animal = std::static_pointer_cast<Animal>(shared_from_this());
}

QGraphicsItem *Sheep::getGraphics() const
{
    return getComponent<SheepGraphicsComponent>()->getGraphicsItem();
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

void Sheep::update(const std::shared_ptr<Field> &field, const std::chrono::milliseconds& tick)
{
    mBlackboard->field = field;
    mBehaviour->update(tick, mBlackboard);
}
