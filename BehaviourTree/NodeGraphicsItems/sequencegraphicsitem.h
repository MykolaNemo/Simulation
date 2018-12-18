#ifndef SEQUENCEGRAPHICSITEM_H
#define SEQUENCEGRAPHICSITEM_H

#include "nodegraphicsitem.h"

class SequenceGraphicsItem: public NodeGraphicsItem
{
public:
    explicit SequenceGraphicsItem(QGraphicsItem *parent = nullptr);

protected:
    void init();
};

#endif // SEQUENCEGRAPHICSITEM_H
