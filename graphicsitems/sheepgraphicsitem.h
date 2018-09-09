#ifndef SHEEPGRAPHICSITEM_H
#define SHEEPGRAPHICSITEM_H

#include <QGraphicsEllipseItem>

class Sheep;

class SheepGraphicsItem : public QGraphicsEllipseItem
{
public:
    explicit SheepGraphicsItem(const std::shared_ptr<Sheep> sheep, QGraphicsItem* parent = nullptr);

private:
    void setup();
    const std::shared_ptr<Sheep> mSheep;
};

#endif // SHEEPGRAPHICSITEM_H
