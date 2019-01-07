#include "scene.h"
#include "models/field.h"
#include "models/fieldobject.h"

#include <QGraphicsEllipseItem>
#include <QThread>
#include <QApplication>
#include <QDebug>

Scene::Scene(QObject *parent):
    QGraphicsScene(parent)
{
    qRegisterMetaType<std::shared_ptr<FieldObject>>("std::shared_ptr<FieldObject>");
    qRegisterMetaType<Position>("Position");
    qRegisterMetaType<QGraphicsItem*>("QGraphicsItem*");
    connect(this, &Scene::positionChanged, this, &Scene::objectPositionChanged, Qt::QueuedConnection);
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
    setSceneRect(QRect(0, 0, mField->getWidth(), mField->getHeight()));

    const auto objects = mField->getObjects();
    for(const auto& object : objects)
    {
        QGraphicsItem* graphicsItem = object->getGraphics();
        if(!graphicsItem) continue;

        this->addItem(graphicsItem);
        graphicsItem->setPos(object->getPosition().x, object->getPosition().y);

        if(mGraphicsItemsMap.count(object) == 0)
        {
            mGraphicsItemsMap.insert(std::make_pair(object, object->getGraphics()));
        }

        object->positionChanged.connect([this](const std::shared_ptr<FieldObject>& obj,
                                               const Position& pos){
            emit positionChanged(obj, pos);
        });

        object->invalidated.connect([this](const std::shared_ptr<FieldObject>& obj){
            if(auto it = mGraphicsItemsMap.find(obj); it != mGraphicsItemsMap.end())
            {
                updateItemInMainThread(it->second);
            }
        });
    }
}

void Scene::updateItemInMainThread(QGraphicsItem* item)
{
    if(!item) return;

    if(QThread::currentThread() != thread() )
    {
        bool ok = QMetaObject::invokeMethod(this, "updateItemInMainThread", Qt::QueuedConnection,
                                            Q_ARG(QGraphicsItem*, item));
        if(!ok)
        {
            qDebug() << "Couldn't invoke method";
        }
        return;
    }
    item->update();
}
