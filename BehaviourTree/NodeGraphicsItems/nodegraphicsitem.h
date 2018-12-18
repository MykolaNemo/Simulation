#ifndef NODEGRAPHICSITEM_H
#define NODEGRAPHICSITEM_H

#include <QGraphicsRectItem>
#include <vector>

class ArrowItem;
class AnchorItem;

class NodeGraphicsItem: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit NodeGraphicsItem(QGraphicsItem *parent = nullptr):
        NodeGraphicsItem (0,0,0,0,parent){}

    explicit NodeGraphicsItem(const QRectF &rect, QGraphicsItem *parent = nullptr):
        NodeGraphicsItem (rect.x(),rect.y(), rect.width(), rect.height(), parent){}

    explicit NodeGraphicsItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = nullptr);

    QPointF getAnchorPoint() const;

    void addOutArrow(ArrowItem* arrowItem);
    void addInArrow(ArrowItem* arrowItem);
    void removeOutArrow(ArrowItem *arrowItem);
    void removeInArrow(ArrowItem *arrowItem);

signals:
    void requestArrowCreation(NodeGraphicsItem*);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value) override;

private:
    void init();

    AnchorItem* mArrowAnchorItem = nullptr;
    std::vector<ArrowItem*> mArrowsOutList;
    std::vector<ArrowItem*> mArrowsInList;
};

#endif // NODEGRAPHICSITEM_H
