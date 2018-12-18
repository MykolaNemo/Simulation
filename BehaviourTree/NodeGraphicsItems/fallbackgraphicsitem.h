#ifndef FALLBACKGRAPHICSITEM_H
#define FALLBACKGRAPHICSITEM_H

#include "nodegraphicsitem.h"

class FallbackGraphicsItem: public NodeGraphicsItem
{
public:
    explicit FallbackGraphicsItem(QGraphicsItem *parent = nullptr);

protected:
    void init();
};

#endif // FALLBACKGRAPHICSITEM_H
