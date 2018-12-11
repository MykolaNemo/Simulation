#include "sequencegraphicsitem.h"

#include <QPainter>

SequenceGraphicsItem::SequenceGraphicsItem(QGraphicsItem *parent):
    NodeGraphicsItem (0,0,130,55,parent)
{
    init();
}

void SequenceGraphicsItem::init()
{
    QPen pen;
    pen.setColor(QColor(0xcc,0x55,0x55));
    setPen(pen);

    QGraphicsSimpleTextItem *textItem = new QGraphicsSimpleTextItem("Sequence", this);
    const auto size = boundingRect().size();
    const auto textItemSize = textItem->boundingRect().size();
    textItem->setPos((size.width() - textItemSize.width())/2.0,
                     (size.height() - textItemSize.height())/2.0);
}
