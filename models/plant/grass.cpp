#include "grass.h"
#include "graphicsitems/grassgraphicsitem.h"
#include "grassfoodcomponent.h"

#include <iostream>

//ugly hack for shared_ptr with protected constructors
class GrassDer:public Grass
{
public:
    GrassDer():Grass(){}
};

void Grass::init()
{

    mGraphics = new GrassGraphicsItem(std::static_pointer_cast<Grass>(shared_from_this()));
    mGraphics->setZValue(0);
}

QGraphicsItem *Grass::getGraphics() const
{
    return mGraphics;
}

std::shared_ptr<Grass> Grass::create()
{
    std::shared_ptr<Grass> grass = std::make_shared<GrassDer>();
    grass->init();
    return grass;
}

void Grass::update(const std::shared_ptr<Field> &/*field*/, const std::chrono::milliseconds& /*tick*/)
{
    auto foodComponent = getComponent<GrassFoodComponent>();
    if(foodComponent && !isOccupied())
    {
        foodComponent->increaseAmount(1);
    }
}
