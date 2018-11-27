#include "sheepgraphicsitem.h"
#include "models/animal/sheep.h"

#include <QBrush>

SheepGraphicsItem::SheepGraphicsItem(std::shared_ptr<Sheep> sheep, QGraphicsItem *parent):
    QGraphicsEllipseItem(parent),
    mSheep(std::move(sheep))
{
    setup();
}

void SheepGraphicsItem::setup()
{
    if(!mSheep) return;

    setBrush(QBrush(QColor(0xCC,0xCC,0xCC), Qt::SolidPattern));
    setRect(0, 0, 20, 15);
    setPos(mSheep->getPosition().x, mSheep->getPosition().y);
}
