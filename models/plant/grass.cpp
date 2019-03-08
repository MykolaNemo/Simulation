#include "grass.h"
#include "graphicsitems/grassgraphicsitem.h"
#include <iostream>

//ugly hack for shared_ptr with protected constructors
class GrassDer:public Grass
{
public:
    GrassDer(Position pos = Position()):Grass(pos){}
};

Grass::Grass(const Position& pos):
    Plant(pos)
{
}

void Grass::init()
{
    mGraphics = new GrassGraphicsItem(std::static_pointer_cast<Grass>(FieldObject::shared_from_this()));
    mGraphics->setZValue(0);
}

QGraphicsItem *Grass::getGraphics() const
{
    return mGraphics;
}

std::shared_ptr<Grass> Grass::create(const Position& pos)
{
    std::shared_ptr<Grass> grass = std::make_shared<GrassDer>(pos);
    grass->init();
    return grass;
}

void Grass::update(const std::shared_ptr<Field> &/*field*/, const std::chrono::milliseconds& /*tick*/)
{
    if(!isOccupied() && (getFoodPoints() < getMaxFoodPoints()))
    {
        increaseFoodPoints(1);
    }
}
