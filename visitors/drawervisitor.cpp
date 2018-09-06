#include "drawervisitor.h"
#include "scene.h"
#include "models/animal/sheep.h"
#include "models/plant/grass.h"

#include <iostream>

#include <QGraphicsEllipseItem>

DrawerVisitor::DrawerVisitor(const std::shared_ptr<Scene> &scene):
    mScene(scene),
    mLastGraphicsItem(nullptr)
{

}

void DrawerVisitor::drawFor(const std::shared_ptr<Sheep>& sheep)
{
    if(!mScene || !sheep) return;

    QGraphicsEllipseItem* sheepItem = new QGraphicsEllipseItem();
    sheepItem->setBrush(QBrush(QColor("#CCCCCC"), Qt::SolidPattern));
    sheepItem->setRect(0,0,20,15);
    sheepItem->setPos(sheep->getPosition().x, sheep->getPosition().y);
    mScene->addItem(sheepItem);
    mLastGraphicsItem = sheepItem;
}

void DrawerVisitor::drawFor(const std::shared_ptr<Grass> &grass)
{
    if(!mScene || !grass) return;

    QGraphicsEllipseItem* grassItem = new QGraphicsEllipseItem(grass->getPosition().x,
                                                               grass->getPosition().y,
                                                               8,8);
    grassItem->setBrush(QBrush(QColor(Qt::green), Qt::SolidPattern));
    mScene->addItem(grassItem);
    mLastGraphicsItem = grassItem;
}

QGraphicsItem *DrawerVisitor::getGraphicsItem() const
{
    return mLastGraphicsItem;
}
