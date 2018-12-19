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

void NodeGraphicsItem::addOutcomeArrow(ArrowItem *arrowItem)
{
    if(!arrowItem) return;

    if(std::find(mOutcomeArrows.begin(), mOutcomeArrows.end(), arrowItem) == mOutcomeArrows.end())
    {
        mOutcomeArrows.push_back(arrowItem);
        arrowItem->setPos(getAnchorPoint());
    }
}

bool NodeGraphicsItem::addIncomeArrow(ArrowItem *arrowItem)
{
    if(!arrowItem || mIncomeArrow)
    {
        return false;
    }

    mIncomeArrow = arrowItem;
    arrowItem->setEndPoint(mapToScene(QPointF(boundingRect().width()/2.0f, 0.0f)));
    return true;
}

void NodeGraphicsItem::removeOutcomeArrow(ArrowItem* arrowItem)
{
    auto deleteIt = std::remove(mOutcomeArrows.begin(), mOutcomeArrows.end(), arrowItem);
    mOutcomeArrows.erase(deleteIt, mOutcomeArrows.end());
}

void NodeGraphicsItem::removeIncomeArrow(ArrowItem* arrowItem)
{
    if(!arrowItem || (mIncomeArrow != arrowItem)) return;

    mIncomeArrow = nullptr;
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
        for(auto outArrow : mOutcomeArrows)
        {
            outArrow->setPos(getAnchorPoint());
        }
        if(mIncomeArrow)
        {
            mIncomeArrow->setEndPoint(mapToScene(QPointF(boundingRect().width()/2.0f, 0.0f)));
        }
        break;
    }
    default:
        break;
    }
    return value;
}
