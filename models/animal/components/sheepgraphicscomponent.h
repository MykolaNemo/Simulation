#ifndef SHEEPGRAPHICSCOMPONENT_H
#define SHEEPGRAPHICSCOMPONENT_H

#include "ECS/Components/graphicscomponent.h"
#include <memory>
#include "graphicsitems/sheepgraphicsitem.h"

class SheepGraphicsComponent: public IGraphicsComponent
{
public:
    SheepGraphicsComponent(const std::shared_ptr<Sheep>& sheep):
        mGraphicsItem(new SheepGraphicsItem(sheep))
    {
        mGraphicsItem->setZValue(1);
    }
    QGraphicsItem* getGraphicsItem() const override{ return mGraphicsItem; }

private:
    QGraphicsItem* mGraphicsItem;
};

#endif // SHEEPGRAPHICSCOMPONENT_H
