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

    virtual void update(const Field&) = 0;

    Position getPosition() const;
    void setPosition(const int x, const int y);
    inline void setPosition(const Position& m_position) {setPosition(m_position.x, m_position.y);}
    bool isOccupied() const;
    void setOccupied(bool occupied);

public:
    boost::signals2::signal<void(const std::shared_ptr<FieldObject>&, const Position&)> positionChanged;
    boost::signals2::signal<void(void)> wasOccupied;
    boost::signals2::signal<void(std::shared_ptr<FieldObject>)> invalidated;

    bool isEated() const;
    void setEated(bool eated);

private:
    Position m_position;
    bool m_occupied = false;
    bool m_eated = false;
};

#endif // FIELDOBJECT_H
