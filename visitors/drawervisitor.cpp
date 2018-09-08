#include "drawervisitor.h"
#include "scene.h"
#include "models/animal/sheep.h"
#include "models/plant/grass.h"
#include "graphicsitems/sheepgraphicsitem.h"
#include "graphicsitems/grassgraphicsitem.h"

#include <iostream>

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

    SheepGraphicsItem* sheepItem = new SheepGraphicsItem(sheep);
    mScene->addItem(sheepItem);
    mLastGraphicsItem = sheepItem;
}

void DrawerVisitor::drawFor(const std::shared_ptr<Grass>& grass)
{
    if(!mScene || !grass) return;

    GrassGraphicsItem* grassItem = new GrassGraphicsItem(grass);
    mScene->addItem(grassItem);
    mLastGraphicsItem = grassItem;
}

QGraphicsItem *DrawerVisitor::getGraphicsItem() const
{
    return mLastGraphicsItem;
}
