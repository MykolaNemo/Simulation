#ifndef GRAPHICSCOMPONENT_H
#define GRAPHICSCOMPONENT_H

#include "../component.h"

class QGraphicsItem;
class GraphicsComponent: public IComponent
{
public:
    GraphicsComponent(QGraphicsItem* graphicsItem)
        : mGraphicsItem(graphicsItem)
    {
    }

    QGraphicsItem* getGraphics() const
    {
        return mGraphicsItem;
    }

    void setGraphicsItem(QGraphicsItem *graphicsItem)
    {
        mGraphicsItem = graphicsItem;
    }

private:
    QGraphicsItem* mGraphicsItem;
};

#endif // GRAPHICSCOMPONENT_H

