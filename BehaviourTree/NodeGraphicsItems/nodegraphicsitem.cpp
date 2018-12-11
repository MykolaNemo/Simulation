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
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    mArrowAnchorItem = new QGraphicsEllipseItem(0,0,10,10,this);
    QPen pen(Qt::blue);
    QBrush brush(Qt::blue, Qt::SolidPattern);
    mArrowAnchorItem->setPen(pen);
    mArrowAnchorItem->setBrush(brush);
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

void NodeGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent* /*event*/)
{
    setCursor(QCursor(Qt::ClosedHandCursor));
    //do not use base class, because we want to receive mouseReleaseEvent
//    QGraphicsRectItem::mousePressEvent(event);
}

void NodeGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(QCursor(Qt::OpenHandCursor));
    QGraphicsRectItem::mouseReleaseEvent(event);
}

QVariant NodeGraphicsItem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    switch (change)
    {
    case QGraphicsItem::ItemTransformHasChanged:
    case QGraphicsItem::ItemVisibleHasChanged:
    {
        const auto size = boundingRect().size();
        const auto anchorItemSize = mArrowAnchorItem->boundingRect().size();
        mArrowAnchorItem->setPos((size.width() - anchorItemSize.width())/2.0,
                                 size.height() - (anchorItemSize.height())/2.0);
    }
    default:
        break;
    }
    return value;
}
