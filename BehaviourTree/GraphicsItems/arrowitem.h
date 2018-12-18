#ifndef ARROWITEM_H
#define ARROWITEM_H

#include <QGraphicsRectItem>

class NodeGraphicsItem;

class ArrowItem: public QGraphicsRectItem
{
public:
    explicit ArrowItem(NodeGraphicsItem* startItem, NodeGraphicsItem* endItem,
                       QGraphicsItem *parent = nullptr);
    int getLength() const;
    void setLength(int length);
    void setStartItem(NodeGraphicsItem* nodeItem);
    void setEndItem(NodeGraphicsItem* nodeItem);
    void setEndPoint(const QPointF& endPoint);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;

private:
    NodeGraphicsItem* mStartItem = nullptr;
    NodeGraphicsItem* mEndItem = nullptr;
    QPointF mEndPoint = QPointF();

    int mLength = 0;
};

#endif // ARROWITEM_H
