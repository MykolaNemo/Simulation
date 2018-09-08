#ifndef GRASSGRAPHICSITEM_H
#define GRASSGRAPHICSITEM_H

#include <QGraphicsEllipseItem>

class Grass;

class GrassGraphicsItem : public QGraphicsEllipseItem
{
public:
    explicit GrassGraphicsItem(const std::shared_ptr<Grass> &grassObject, QGraphicsItem *parent = nullptr);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    void setup();
    const std::shared_ptr<Grass> mGrassObject;
};

#endif // GRASSGRAPHICSITEM_H
