#ifndef ARROWITEM_H
#define ARROWITEM_H

#include <QGraphicsRectItem>

class NodeGraphicsItem;

class ArrowItem: public QGraphicsItem
{
public:
    explicit ArrowItem(NodeGraphicsItem* startItem, NodeGraphicsItem* endItem,
                       QGraphicsItem *parent = nullptr);
    ~ArrowItem();
    NodeGraphicsItem* getStartItem() const;
    void setStartItem(NodeGraphicsItem* nodeItem);
    bool setEndItem(NodeGraphicsItem* nodeItem);
    void setEndPoint(const QPointF& endPointItemCoord);
    QRectF boundingRect() const override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    NodeGraphicsItem* mStartItem = nullptr;
    NodeGraphicsItem* mEndItem = nullptr;
    QPointF mEndPoint = QPointF(); //local coordinates
};

#endif // ARROWITEM_H
