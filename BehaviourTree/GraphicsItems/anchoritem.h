#ifndef ANCHORITEM_H
#define ANCHORITEM_H

#include <QGraphicsEllipseItem>
#include <QObject>

class AnchorItem: public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    AnchorItem(QGraphicsItem* parent = nullptr);

signals:
    void pressed();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif // ANCHORITEM_H
