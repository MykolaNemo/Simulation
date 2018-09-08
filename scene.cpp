#include "scene.h"
#include "models/field.h"
#include "models/fieldobject.h"
#include "visitors/drawervisitor.h"

#include <QGraphicsEllipseItem>
#include <QTimer>
#include <iostream>

Scene::Scene(QObject *parent):
    QGraphicsScene(parent)
{
    qRegisterMetaType<std::shared_ptr<FieldObject>>("std::shared_ptr<FieldObject>");
    qRegisterMetaType<Position>("Position");
    connect(this, &Scene::positionChanged, this, &Scene::objectPositionChanged);
}

void Scene::objectPositionChanged(const std::shared_ptr<FieldObject> &object, const Position &pos)
{
    auto it = mGraphicsItemsMap.find(object);
    if(it != mGraphicsItemsMap.end())
    {
        if(it->second)
        {
            it->second->setPos(pos.x, pos.y);
        }
    }
}

std::shared_ptr<Scene> Scene::create(const std::shared_ptr<Field> &field)
{
    std::shared_ptr<Scene> scene(new Scene());
    scene->mDrawer = std::make_shared<DrawerVisitor>(scene);
    scene->setField(field);
    return scene;
}

void Scene::setField(const std::shared_ptr<Field> &field)
{
    mGraphicsItemsMap.clear();
    clear();

    mField = field;

    if(!mField) return;
    setSceneRect(QRect(0, 0, field->getWidth(), field->getHeight()));

    const auto objects = mField->getObjects();
    for(const auto& object : objects)
    {
        object->positionChanged.connect([this](const std::shared_ptr<FieldObject>& obj, const Position& pos){
           emit positionChanged(obj, pos);
        });
        object->invalidated.connect([this](const std::shared_ptr<FieldObject>& obj){
            if(auto it = mGraphicsItemsMap.find(obj); it != mGraphicsItemsMap.end())
            {
                it->second->update();
            }
        });

        object->draw(mDrawer);
        if(mGraphicsItemsMap.count(object) == 0)
        {
            auto pair = std::make_pair(object, mDrawer->getGraphicsItem());
            mGraphicsItemsMap.insert(pair);
        }
    }
}
