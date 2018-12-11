#include "nodegraphicsitem.h"

#include <QCursor>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>

NodeGraphicsItem::NodeGraphicsItem(QGraphicsItem *parent):
    QGraphicsRectItem (parent)
{
    init();
}

NodeGraphicsItem::NodeGraphicsItem(const QRectF &rect, QGraphicsItem *parent):
    QGraphicsRectItem (rect, parent)
{
    init();
}

NodeGraphicsItem::NodeGraphicsItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent):
    QGraphicsRectItem (x,y,w,h,parent)
{
    init();
}

void NodeGraphicsItem::init()
{
    setAcceptHoverEvents(true);
}

void NodeGraphicsItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setCursor(QCursor(Qt::OpenHandCursor));
    QGraphicsRectItem::hoverEnterEvent(event);
}

void NodeGraphicsItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setCursor(QCursor(Qt::ArrowCursor));
    QGraphicsRectItem::hoverLeaveEvent(event);
}

void NodeGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    mPressed = true;
    mPressedPoint = event->pos();
    setCursor(QCursor(Qt::ClosedHandCursor));
    //do not use base class, because we want to receive mouseReleaseEvent
//    QGraphicsRectItem::mousePressEvent(event);
}

void NodeGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    mPressed = false;
    mPressedPoint = QPoint();
    setCursor(QCursor(Qt::OpenHandCursor));
    QGraphicsRectItem::mouseReleaseEvent(event);
}

void NodeGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(mPressed)
    {
        QPointF delta = event->pos() - mPressedPoint;
        moveBy(delta.x(), delta.y());
    }
    QGraphicsRectItem::mouseMoveEvent(event);
}
