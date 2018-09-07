#include "drawervisitor.h"
#include "scene.h"
#include "models/animal/sheep.h"
#include "models/plant/grass.h"

#include <iostream>

#include <QGraphicsEllipseItem>
#include <QThread>
#include <QMetaMethod>

DrawerVisitor::DrawerVisitor(const std::shared_ptr<Scene> &scene):
    mScene(scene),
    mLastGraphicsItem(nullptr)
{
    qRegisterMetaType<std::shared_ptr<Grass>>("std::shared_ptr<Grass>");
    qRegisterMetaType<std::shared_ptr<Sheep>>("std::shared_ptr<Sheep>");
}

void DrawerVisitor::drawFor(const std::shared_ptr<Sheep>& sheep)
{
    if(!mScene || !sheep) return;

    if(thread() != QThread::currentThread())
    {
        QMetaObject::invokeMethod(this, "drawFor", Qt::QueuedConnection,
                                  Q_ARG(std::shared_ptr<Sheep>, sheep));
        return;
    }

    QGraphicsEllipseItem* sheepItem = new QGraphicsEllipseItem();
    sheepItem->setBrush(QBrush(QColor("#CCCCCC"), Qt::SolidPattern));
    sheepItem->setRect(0,0,20,15);
    sheepItem->setPos(sheep->getPosition().x, sheep->getPosition().y);
    mScene->addItem(sheepItem);
    mLastGraphicsItem = sheepItem;
}

void DrawerVisitor::drawFor(const std::shared_ptr<Grass>& grass)
{
    if(!mScene || !grass) return;

    if(thread() != QThread::currentThread())
    {
        QMetaObject::invokeMethod(this, "drawFor", Qt::QueuedConnection,
                                  Q_ARG(std::shared_ptr<Grass>, grass));
        return;
    }


    QGraphicsEllipseItem* grassItem = new QGraphicsEllipseItem(grass->getPosition().x,
                                                               grass->getPosition().y,
                                                               8,8);
    if(grass->isEated())
    {
        grassItem->setBrush(QBrush(QColor(Qt::darkYellow), Qt::SolidPattern));
    }
    else
    {
        grassItem->setBrush(QBrush(QColor(Qt::green), Qt::SolidPattern));
    }
    mScene->addItem(grassItem);
    mLastGraphicsItem = grassItem;
}

QGraphicsItem *DrawerVisitor::getGraphicsItem() const
{
    return mLastGraphicsItem;
}
