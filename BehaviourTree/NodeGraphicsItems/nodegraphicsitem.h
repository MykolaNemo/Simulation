#ifndef NODEGRAPHICSITEM_H
#define NODEGRAPHICSITEM_H

#include <QGraphicsRectItem>

class NodeGraphicsItem: public QGraphicsRectItem
{
public:
    explicit NodeGraphicsItem(QGraphicsItem *parent = nullptr);
    explicit NodeGraphicsItem(const QRectF &rect, QGraphicsItem *parent = nullptr);
    explicit NodeGraphicsItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = nullptr);

protected:
    virtual void init();
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value) override;

private:
    QGraphicsEllipseItem* mArrowAnchorItem;
};

#endif // NODEGRAPHICSITEM_H
