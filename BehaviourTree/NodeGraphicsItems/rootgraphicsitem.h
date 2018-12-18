#ifndef ROOTGRAPHICSITEM_H
#define ROOTGRAPHICSITEM_H

#include "nodegraphicsitem.h"

class RootGraphicsItem: public NodeGraphicsItem
{
public:
    explicit RootGraphicsItem(QGraphicsItem *parent = nullptr);

private:
    void init();
};

#endif // ROOTGRAPHICSITEM_H
