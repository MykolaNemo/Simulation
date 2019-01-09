#include "grassgraphicsitem.h"
#include "models/plant/grass.h"

#include <QBrush>
#include <QPainter>

const QColor GrassGraphicsItem::eatedColor = QColor(127, 102, 48);
const QColor GrassGraphicsItem::notEatedColor = QColor(127, 255, 48);
QBrush GrassGraphicsItem::painterBrush = QBrush(GrassGraphicsItem::notEatedColor, Qt::SolidPattern);

GrassGraphicsItem::GrassGraphicsItem(std::shared_ptr<Grass> grassObject, QGraphicsItem* parent):
    QGraphicsEllipseItem(0, 0, 8, 8, parent),
    mGrassObject(std::move(grassObject))
{
    setup();
}

void GrassGraphicsItem::setup()
{
    if(!mGrassObject) return;

    setPos(mGrassObject->getPosition().x, mGrassObject->getPosition().y);
    setRect(0, 0, 8, 8);

    int greenness = eatedColor.green() +
            (notEatedColor.green() - eatedColor.green())*
            mGrassObject->getFoodPoints()/mGrassObject->getMaxFoodPoints();

    QColor c(eatedColor.red(), greenness, eatedColor.blue());
    setBrush(QBrush(c, Qt::SolidPattern));
}

void GrassGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    const int greenness = eatedColor.green() +
                          (notEatedColor.green() - eatedColor.green())*
                          mGrassObject->getFoodPoints()/mGrassObject->getMaxFoodPoints();

    const QColor c(eatedColor.red(), greenness, eatedColor.blue());
    painterBrush.setColor(c);
    setBrush(painterBrush);
    painter->setRenderHint(QPainter::Antialiasing);
    QGraphicsEllipseItem::paint(painter, option, widget);
}
