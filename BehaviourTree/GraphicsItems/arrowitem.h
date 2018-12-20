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
    void setEndPoint(const QPointF& endPoint);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;

private:
    NodeGraphicsItem* mStartItem = nullptr;
    NodeGraphicsItem* mEndItem = nullptr;
    QPointF mEndPoint = QPointF();
};

#endif // ARROWITEM_H
