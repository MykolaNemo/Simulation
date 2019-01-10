#ifndef NODEGRAPHICSITEM_H
#define NODEGRAPHICSITEM_H

#include <QGraphicsRectItem>
#include <vector>
#include <memory>

class Tree;
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
    ~NodeGraphicsItem() override;

    QPointF getAnchorPoint() const;

    void addOutcomeArrow(ArrowItem* arrowItem);
    bool addIncomeArrow(ArrowItem* arrowItem);
    void removeOutcomeArrow(ArrowItem *arrowItem);
    void removeIncomeArrow(ArrowItem *arrowItem);

    virtual std::shared_ptr<Tree> getTreeModel() const = 0;

signals:
    void requestArrowCreation(NodeGraphicsItem*);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void hideAnchorItem();

private:
    void init();

    AnchorItem* mArrowAnchorItem = nullptr;
    std::vector<ArrowItem*> mOutcomeArrows;
    ArrowItem* mIncomeArrow = nullptr;
};

#endif // NODEGRAPHICSITEM_H
