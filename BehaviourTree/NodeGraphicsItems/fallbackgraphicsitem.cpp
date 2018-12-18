#include "fallbackgraphicsitem.h"

#include <QPainter>

FallbackGraphicsItem::FallbackGraphicsItem(QGraphicsItem *parent):
    NodeGraphicsItem (0,0,130,55,parent)
{
    init();
}

void FallbackGraphicsItem::init()
{
    QPen pen;
    pen.setWidth(2);
    pen.setColor(QColor(0xcc,0xcc,0x55));
    setPen(pen);

    QGraphicsSimpleTextItem *textItem = new QGraphicsSimpleTextItem("Fallback", this);
    const auto size = boundingRect().size();
    const auto textItemSize = textItem->boundingRect().size();
    textItem->setPos((size.width() - textItemSize.width())/2.0,
                     (size.height() - textItemSize.height())/2.0);
}
