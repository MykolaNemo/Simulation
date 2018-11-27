#ifndef FIELDOBJECT_H
#define FIELDOBJECT_H

#include "position.h"
#include "boost/signals2/signal.hpp"
#include "state/state.h"

class QGraphicsItem;
class FieldObject: public std::enable_shared_from_this<FieldObject>
{
public:
    FieldObject(const Position& _position = Position());

    virtual ~FieldObject() = default;
    FieldObject(const FieldObject& other) = default;
    FieldObject(FieldObject&& other) = default;
    FieldObject& operator =(const FieldObject& other) = default;
    FieldObject& operator =(FieldObject&& other) = default;

    virtual void update(const Field&) = 0;
    virtual QGraphicsItem* getGraphics() const = 0;

    inline Position getPosition() const { return m_position; }
    void setPosition(const int x, const int y);
    inline void setPosition(const Position& m_position) {setPosition(m_position.x, m_position.y);}
    bool isInUse() const;
    void setInUse(bool occupied);
    int getFoodPoints() const;
    void setFoodPoints(const int foodPoints);

public:
    boost::signals2::signal<void(const std::shared_ptr<FieldObject>&, const Position&)> positionChanged;
    boost::signals2::signal<void(void)> wasOccupied;
    boost::signals2::signal<void(const std::shared_ptr<FieldObject>&)> invalidated;

    int getMaxFoodPoints() const;

private:
    Position m_position;
    bool mInUse = false;
    const int mMaxFoodPoints = 200;
    int mFoodPoints = mMaxFoodPoints;
};

#endif // FIELDOBJECT_H
