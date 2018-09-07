#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <memory>
#include <set>

#include "size2d.h"
#include "position.h"
#include <boost/signals2/signal.hpp>

class FieldObject;
class Animal;
enum class FieldObjectType;

class Field
{
public:
    Field(int _width, int _height);

    void addObjects(const std::vector<std::shared_ptr<FieldObject> > &objects);
    void addObject(const std::shared_ptr<FieldObject> &object);
    std::vector<std::shared_ptr<FieldObject> > getObjectsAt(const int x, const int y) const;
    inline std::vector<std::shared_ptr<FieldObject> > getObjectsAt(const Position& position) const
    { return getObjectsAt(position.x, position.y); }

    std::vector<std::shared_ptr<FieldObject>> getObjects() const;
    std::shared_ptr<FieldObject> getClosestObject(const Position &centralPoint,
                                                  const type_info &type) const;
    std::shared_ptr<FieldObject> getClosestUnoccupiedObject(const Position &centralPoint,
                                                  const type_info &type) const;

    Size2D getSize() const;
    inline int getWidth() const {return getSize().width;}
    inline int getHeight() const {return getSize().height;}

private:
    Position randomPosition() const;

    boost::signals2::signal<void(void)> fieldWasReseted;

private:
    Size2D size;
    std::vector<std::shared_ptr<FieldObject>> m_objects;
};

#endif // FIELD_H
