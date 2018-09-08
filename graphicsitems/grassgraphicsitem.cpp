#include "grassgraphicsitem.h"
#include "models/plant/grass.h"

#include <QBrush>

GrassGraphicsItem::GrassGraphicsItem(const std::shared_ptr<Grass>& grassObject, QGraphicsItem* parent):
    QGraphicsEllipseItem(0, 0, 8, 8, parent),
    mGrassObject(grassObject)
{
    setup();
}

void GrassGraphicsItem::setup()
{
    if(!mGrassObject) return;

    setPos(mGrassObject->getPosition().x, mGrassObject->getPosition().y);
    setRect(0, 0, 8, 8);
    if(mGrassObject->isEated())
    {
        setBrush(QBrush(QColor(Qt::darkYellow), Qt::SolidPattern));
    }
    else
    {
        setBrush(QBrush(QColor(Qt::green), Qt::SolidPattern));
    }
}

void GrassGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(mGrassObject)
    {
        if(mGrassObject->isEated())
        {
            setBrush(QBrush(QColor(Qt::darkYellow), Qt::SolidPattern));
        }
        else
        {
            setBrush(QBrush(QColor(Qt::green), Qt::SolidPattern));
        }
    }
    QGraphicsEllipseItem::paint(painter, option, widget);
}
