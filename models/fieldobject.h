#ifndef FIELDOBJECT_H
#define FIELDOBJECT_H

#include <chrono>

#include "position.h"
#include "boost/signals2/signal.hpp"
#include "models/field.h"
#include "ECS/entity.h"

class QGraphicsItem;
class FieldObject: public IEntity
{
public:
    FieldObject(const Position& _position = Position());

    virtual ~FieldObject() = default;
    FieldObject(const FieldObject& other) = default;
    FieldObject(FieldObject&& other) = default;
    FieldObject& operator =(const FieldObject& other) = default;
    FieldObject& operator =(FieldObject&& other) = default;

    virtual void update(const std::shared_ptr<Field> &, const std::chrono::milliseconds&) = 0;
    virtual QGraphicsItem* getGraphics() const = 0;

    Position getPosition() const;
    void setPosition(const int x, const int y);
    inline void setPosition(const Position& pos) {setPosition(pos.x, pos.y);}

public:
    boost::signals2::signal<void(const std::shared_ptr<FieldObject>&, const Position)> positionChanged;
    boost::signals2::signal<void(const std::shared_ptr<FieldObject>&)> invalidated;
};

#endif // FIELDOBJECT_H
