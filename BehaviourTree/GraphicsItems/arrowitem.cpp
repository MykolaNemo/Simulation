#include "arrowitem.h"
#include "NodeGraphicsItems/nodegraphicsitem.h"
#include "tree.h"

#include <QPainter>
#include <QDebug>
#include <QEvent>
#include <cmath>

ArrowItem::ArrowItem(NodeGraphicsItem *startItem, NodeGraphicsItem *endItem,
                     QGraphicsItem *parent):
    QGraphicsItem (parent)
{
    setStartItem(startItem);
    setEndItem(endItem);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

ArrowItem::~ArrowItem()
{
    if(mStartItem)
    {
        mStartItem->removeOutcomeArrow(this);
    }
    if(mEndItem)
    {
        mEndItem->removeIncomeArrow(this);
    }
    if(mStartItem && mEndItem)
    {
        auto parentTreeModel = mStartItem->getTreeModel();
        parentTreeModel->removeChild(mEndItem->getTreeModel());
    }
}

NodeGraphicsItem* ArrowItem::getStartItem() const
{
    return mStartItem;
}

void ArrowItem::setStartItem(NodeGraphicsItem *startNodeItem)
{
    mStartItem = startNodeItem;
    if(mStartItem)
    {
        mStartItem->addOutcomeArrow(this);
        update();
    }
}

bool ArrowItem::setEndItem(NodeGraphicsItem *endNodeItem)
{
    if(endNodeItem)
    {
        if(endNodeItem->addIncomeArrow(this))
        {
            mEndItem = endNodeItem;
            if(mStartItem)
            {
                auto parentTreeModel = mStartItem->getTreeModel();
                parentTreeModel->addChild(mEndItem->getTreeModel());
            }
            update();
            return true;
        }
    }
    else
    {
        mEndItem = endNodeItem;
    }
    update();
    return false;
}

void ArrowItem::setEndPoint(const QPointF &endPoint)
{
    mEndPoint = endPoint;
    update();
}

void ArrowItem::paint(QPainter *painter, const QStyleOptionGraphicsItem* /*option*/, QWidget* /*widget*/)
{
    painter->save();
    if(isSelected())
    {
        painter->setPen(QPen(QBrush(Qt::blue), 2));
    }
    else
    {
        painter->setPen(QPen(QBrush(QColor(0x99,0xcc,0x99)), 2));
    }

    const QRectF& rect = boundingRect();
    const int x = rect.x();
    const int y = rect.y();

    QPointF endPoint;
    if(x == 0 && y < 0)// top-right quarter
    {
        endPoint = rect.topRight();
    }
    else if(x == 0 && y == 0)// bottom-right quarter
    {
        endPoint = rect.bottomRight();
    }
    else if(x < 0 && y == 0)// bottom-left quarter
    {
        endPoint = rect.bottomLeft();
    }
    else if(x < 0 && y < 0)// top-left quarter
    {
        endPoint = rect.topLeft();
    }

    painter->drawLine(QPointF(), endPoint);
    painter->setPen(QPen(QBrush(Qt::red), 2));
    painter->drawEllipse(endPoint, 3, 3);

    painter->restore();
}

QRectF ArrowItem::boundingRect() const
{
    QPointF point = mapFromScene(mEndPoint);
    const QPoint leftTop(qMin<float>(0.0f, point.x()), qMin<float>(0.0f, point.y()));
    const QPoint bottomRight(qMax<float>(0.0f, point.x()), qMax<float>(0.0f, point.y()));
    return {leftTop, bottomRight};
}
