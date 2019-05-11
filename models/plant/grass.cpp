#include "grass.h"
#include "graphicsitems/grassgraphicsitem.h"
#include "ECS/Components/foodcomponent.h"
#include "ECS/Components/graphicscomponent.h"

#include <iostream>

//ugly hack for shared_ptr with protected constructors
class GrassDer:public Grass {};

void Grass::init()
{
    auto grassGraphicsItem = new GrassGraphicsItem(std::static_pointer_cast<Grass>(shared_from_this()));
    grassGraphicsItem->setZValue(0);
    addComponent(std::make_shared<GraphicsComponent>(grassGraphicsItem));
}

QGraphicsItem *Grass::getGraphics() const
{
    return getComponent<GraphicsComponent>()->getGraphics();
}

std::shared_ptr<Grass> Grass::create()
{
    std::shared_ptr<Grass> grass = std::make_shared<GrassDer>();
    grass->init();
    return grass;
}

void Grass::update(const std::shared_ptr<Field> &/*field*/, const std::chrono::milliseconds& /*tick*/)
{
    auto foodComponent = getComponent<FoodComponent>();
    if(foodComponent && !isOccupied())
    {
        foodComponent->increaseAmount(1);
        invalidated(std::static_pointer_cast<FieldObject>(shared_from_this()));
    }
}
