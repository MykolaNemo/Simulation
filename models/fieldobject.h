#ifndef FIELDOBJECT_H
#define FIELDOBJECT_H

#include "position.h"
#include "boost/signals2/signal.hpp"
#include "models/field.h"
#include "virtual_enable_shared_from_this.h"
#include <chrono>

class QGraphicsItem;
class FieldObject: public virtual_enable_shared_from_this<FieldObject>
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

    inline Position getPosition() const { return m_position; }
    void setPosition(const int x, const int y);
    inline void setPosition(const Position& m_position) {setPosition(m_position.x, m_position.y);}

public:
    boost::signals2::signal<void(const std::shared_ptr<FieldObject>&, const Position&)> positionChanged;
    boost::signals2::signal<void(const std::shared_ptr<FieldObject>&)> invalidated;

private:
    Position m_position;
};

#endif // FIELDOBJECT_H
