#ifndef ANCHORITEM_H
#define ANCHORITEM_H

#include <QGraphicsEllipseItem>
#include <QObject>

class QMouseEvent;

class AnchorItem: public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    AnchorItem(QGraphicsItem* parent = nullptr);

signals:
    void pressed();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

//    ArrowItem* mArrowItem = nullptr;
};

#endif // ANCHORITEM_H
