#include "sheep.h"
#include <iostream>
#include "graphicsitems/sheepgraphicsitem.h"
#include "behaviours/blackboards/blackboard.h"
#include "behaviours/blackboards/sheepblackboard.h"

SheepBehaviour Sheep::mBehaviour = SheepBehaviour();

//ugly hack for shared_ptr with protected constructors
class SheepDer:public Sheep
{
public:
    SheepDer(Position pos = Position()): Sheep(pos){}
};

Sheep::Sheep(Position pos):
    Animal(pos),
    mBlackboard(std::make_shared<SheepBlackboard>())
{
}

void Sheep::init()
{
    mGraphics = new SheepGraphicsItem(std::static_pointer_cast<Sheep>(shared_from_this()));
    mGraphics->setZValue(1);
//    mBlackboard->sheep = std::static_pointer_cast<Sheep>(shared_from_this());
    mBlackboard->actor = shared_from_this();
}

QGraphicsItem *Sheep::getGraphics() const
{
    return mGraphics;
}

std::shared_ptr<Sheep> Sheep::create(const Position& pos)
{
    std::shared_ptr<Sheep> sheep = std::make_shared<SheepDer>(pos);
    sheep->init();
    return sheep;
}

int Sheep::getHungerThreshold() const
{
    return mHungerThreshold;
}

void Sheep::update(const Field &/*field*/, const std::chrono::milliseconds& tick)
{
    mBehaviour.update(tick, mBlackboard);
}
