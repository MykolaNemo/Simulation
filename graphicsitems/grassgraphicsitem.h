#ifndef GRASSGRAPHICSITEM_H
#define GRASSGRAPHICSITEM_H

#include <QGraphicsEllipseItem>

class Grass;
class GrassGraphicsItem : public QGraphicsEllipseItem
{
public:
    explicit GrassGraphicsItem(const std::shared_ptr<Grass> grassObject, QGraphicsItem *parent = nullptr);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    void setup();
    const std::shared_ptr<Grass> mGrassObject;
    static const QColor eatedColor;
    static const QColor notEatedColor;
};

#endif // GRASSGRAPHICSITEM_H
