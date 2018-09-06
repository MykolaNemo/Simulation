#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <memory>
#include "position.h"

class Field;
class FieldObject;

class Scene: public QGraphicsScene, public std::enable_shared_from_this<Scene>
{
    Q_OBJECT
public:
    static std::shared_ptr<Scene> create(const std::shared_ptr<Field> &field);
    void setField(const std::shared_ptr<Field>& field);

signals:
    void positionChanged(const std::shared_ptr<FieldObject>& object, const Position& pos);

private:
    Scene(QObject *parent = nullptr);
    Scene(const Scene& other) = default;

    void objectPositionChanged(const std::shared_ptr<FieldObject>& object, const Position& pos);

private:
    std::shared_ptr<Field> mField;
    std::map<const std::shared_ptr<FieldObject>, QGraphicsItem*> mGraphicsItemsMap;
};

#endif // SCENE_H
