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

    std::shared_ptr<DrawerVisitor> drawer(new DrawerVisitor(shared_from_this()));
    const auto objects = mField->getObjects();
    for(const auto& object : objects)
    {
        object->positionChanged.connect([this](const std::shared_ptr<FieldObject>& object, const Position& pos){
           emit positionChanged(object, pos);
        });
        object->draw(drawer);
        if(mGraphicsItemsMap.count(object) == 0)
        {
            auto pair = std::make_pair(object, drawer->getGraphicsItem());
            mGraphicsItemsMap.insert(pair);
        }
    }
}
