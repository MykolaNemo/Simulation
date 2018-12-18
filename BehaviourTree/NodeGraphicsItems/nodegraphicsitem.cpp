#include "nodegraphicsitem.h"

#include <QCursor>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include <QPainter>
#include "GraphicsItems/anchoritem.h"
#include "GraphicsItems/arrowitem.h"

NodeGraphicsItem::NodeGraphicsItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent):
    QGraphicsRectItem (x,y,w,h,parent)
{
    init();
}

QPointF NodeGraphicsItem::getAnchorPoint() const
{
    return mArrowAnchorItem->mapToScene(mArrowAnchorItem->boundingRect().center());
}

void NodeGraphicsItem::addOutArrow(ArrowItem *arrowItem)
{
    if(!arrowItem) return;

    if(std::find(mArrowsOutList.begin(), mArrowsOutList.end(), arrowItem) == mArrowsOutList.end())
    {
        mArrowsOutList.push_back(arrowItem);
    }
    arrowItem->setPos(getAnchorPoint());
}

void NodeGraphicsItem::addInArrow(ArrowItem *arrowItem)
{
    if(!arrowItem) return;

    if(std::find(mArrowsInList.begin(), mArrowsInList.end(), arrowItem) == mArrowsInList.end())
    {
        mArrowsInList.push_back(arrowItem);
    }

    arrowItem->setEndPoint(mapToScene(QPointF(boundingRect().width()/2.0f, 0.0f)));
}

void NodeGraphicsItem::removeOutArrow(ArrowItem* arrowItem)
{
    auto deleteIt = std::remove(mArrowsOutList.begin(), mArrowsOutList.end(), arrowItem);
    mArrowsOutList.erase(deleteIt, mArrowsOutList.end());
}

void NodeGraphicsItem::removeInArrow(ArrowItem* arrowItem)
{
    auto deleteIt = std::remove(mArrowsInList.begin(), mArrowsInList.end(), arrowItem);
    mArrowsInList.erase(deleteIt, mArrowsInList.end());
}

void NodeGraphicsItem::init()
{
    setCursor(QCursor(Qt::OpenHandCursor));
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    setAcceptHoverEvents(true);

    mArrowAnchorItem = new AnchorItem(this);
    connect(mArrowAnchorItem, &AnchorItem::pressed, [this](){
        emit requestArrowCreation(this);
    });
}

void NodeGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if(!event->buttons().testFlag(Qt::LeftButton))
    {
        event->accept();
        return;
    }

    const QRectF rect = mArrowAnchorItem->boundingRect();
    const QRectF mappedRect(mArrowAnchorItem->mapToItem(this,rect.topLeft()),rect.size());
    if(!mappedRect.contains(event->pos()))
    {
        setCursor(QCursor(Qt::ClosedHandCursor));
        //do not use base class, because we want to receive mouseReleaseEvent
    }
    else
    {
        //ignore mouse press to prevent drag at anchor point
        event->ignore();
    }
}

void NodeGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    const QRectF rect = mArrowAnchorItem->boundingRect();
    const QRectF mappedRect(mArrowAnchorItem->mapToItem(this,rect.topLeft()),rect.size());
    if(!mappedRect.contains(event->pos()))
    {
        setCursor(QCursor(Qt::OpenHandCursor));
    }
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
        break;
    }
    case QGraphicsItem::ItemPositionHasChanged:
    {
        for(auto outArrow : mArrowsOutList)
        {
            outArrow->setPos(getAnchorPoint());
        }
        for(auto outArrow : mArrowsInList)
        {
            outArrow->setEndPoint(mapToScene(QPointF(boundingRect().width()/2.0f, 0.0f)));
        }
        break;
    }
    default:
        break;
    }
    return value;
}
