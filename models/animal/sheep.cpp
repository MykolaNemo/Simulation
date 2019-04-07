#include "sheep.h"
#include <iostream>
#include "graphicsitems/sheepgraphicsitem.h"
#include "behaviours/blackboards/blackboard.h"
#include "ECS/Components/graphicscomponent.h"
#include "components/animalvelocitycomponent.h"
#include "components/sheepgraphicscomponent.h"
#include "components/animalhungercomponent.h"

SheepBehaviour Sheep::mBehaviour = SheepBehaviour();

//ugly hack for shared_ptr with protected constructors
class SheepDer:public Sheep
{
public:
    SheepDer(Position pos = Position()): Sheep(pos){}
};

Sheep::Sheep(const Position pos):
    Animal(pos),
    mBlackboard(std::make_shared<Blackboard>())
{
}

void Sheep::init()
{
    addComponent(std::make_shared<SheepGraphicsComponent>(std::static_pointer_cast<Sheep>(shared_from_this())));
    mBlackboard->animal = std::static_pointer_cast<Animal>(FieldObject::shared_from_this());
}

QGraphicsItem *Sheep::getGraphics() const
{
    return getComponent<SheepGraphicsComponent>()->getGraphicsItem();
}

std::shared_ptr<Sheep> Sheep::create(const Position& pos)
{
    auto sheep = std::make_shared<SheepDer>(pos);
    sheep->init();
    return sheep;
}

int Sheep::getHungerThreshold() const
{
    return getComponent<AnimalHungerComponent>()->getHungerMaximum();
}

void Sheep::update(const std::shared_ptr<Field> &field, const std::chrono::milliseconds& tick)
{
    mBlackboard->field = field;
    mBehaviour.update(tick, mBlackboard);
}
