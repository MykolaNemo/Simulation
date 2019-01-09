#ifndef SHEEPGRAPHICSITEM_H
#define SHEEPGRAPHICSITEM_H

#include <QGraphicsEllipseItem>
#include <memory>

class Sheep;

class SheepGraphicsItem : public QGraphicsEllipseItem
{
public:
    explicit SheepGraphicsItem(std::shared_ptr<Sheep> sheep, QGraphicsItem* parent = nullptr);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    void setup();
    const std::shared_ptr<Sheep> mSheep;
};

#endif // SHEEPGRAPHICSITEM_H
