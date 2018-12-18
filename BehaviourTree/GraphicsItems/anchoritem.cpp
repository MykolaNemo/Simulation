#include "anchoritem.h"

#include <QCursor>
#include <QPen>
#include <QDebug>

AnchorItem::AnchorItem(QGraphicsItem* parent):
    QGraphicsEllipseItem(0,0,10,10, parent)
{
    setAcceptHoverEvents(true);
    setCursor(QCursor(Qt::PointingHandCursor));
    QPen pen(Qt::blue);
    QBrush brush(Qt::blue, Qt::SolidPattern);
    setPen(pen);
    setBrush(brush);
}

void AnchorItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsEllipseItem::mousePressEvent(event);
    qDebug()<<"Anchor pressed";
    emit pressed();
}
