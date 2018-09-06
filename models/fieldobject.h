#ifndef FIELDOBJECT_H
#define FIELDOBJECT_H

#include "position.h"
#include "canthink.h"
#include "canbedrawn.h"
#include "boost/signals2/signal.hpp"
#include "state/state.h"

//class FieldObject: public CanThink,
class FieldObject: public CanBeDrawn,
                   public std::enable_shared_from_this<FieldObject>
{
public:
    FieldObject(const Position& _position = Position());

    virtual ~FieldObject();
    FieldObject(const FieldObject& other) = default;
    FieldObject(FieldObject&& other) = default;
    FieldObject& operator =(const FieldObject& other) = default;
    FieldObject& operator =(FieldObject&& other) = default;

    Position getPosition() const;
    void setPosition(const int x, const int y);
    void setPosition(const Position& m_position);

    virtual void update(const std::shared_ptr<Field>&) = 0;

//    void transferToNextState(const std::shared_ptr<Field>& field) = 0;

public:
    boost::signals2::signal<void(const std::shared_ptr<FieldObject>&, const Position&)> positionChanged;
    boost::signals2::signal<void(const std::shared_ptr<FieldObject>&)> nextTaskRequest;

protected:
    Position m_position;
};

#endif // FIELDOBJECT_H
