#ifndef GRAPHICSCOMPONENT_H
#define GRAPHICSCOMPONENT_H

#include "../component.h"

class QGraphicsItem;
class IGraphicsComponent: public IComponent
{
public:
    virtual ~IGraphicsComponent() = default;
    virtual QGraphicsItem* getGraphicsItem() const = 0;
};

#endif // GRAPHICSCOMPONENT_H
