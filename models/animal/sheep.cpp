#include "sheep.h"
#include <iostream>
#include "graphicsitems/sheepgraphicsitem.h"

//ugly hack for shared_ptr with protected constructors
class SheepDer:public Sheep
{
public:
    SheepDer(Position pos = Position()): Sheep(pos){}
};

Sheep::Sheep(Position pos):
    Animal(pos)
{
}

void Sheep::init()
{
    mGraphics = new SheepGraphicsItem(std::static_pointer_cast<Sheep>(shared_from_this()));
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
