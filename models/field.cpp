#include "field.h"
#include "fieldobject.h"

#include <random>
#include <functional>
#include <iostream>

double objectDistanceSquared (const Position& firstPos, const Position& secondPos)
{
    return std::pow(std::abs(firstPos.x - secondPos.x),2) +
            std::pow(std::abs(firstPos.y - secondPos.y),2);
}

Field::Field(int _width, int _height):
    size(Size2D(_width, _height))
{
}

void Field::addObjects(const std::vector<std::shared_ptr<FieldObject>> &objects)
{
    for(const auto& object : objects)
    {
        addObject(object);
    }
}

void Field::addObject(const std::shared_ptr<FieldObject> &object)
{
    object->setPosition(randomPosition());
    m_objects.push_back(object);
}

std::vector<std::shared_ptr<FieldObject>> Field::getObjectsAt(const int x, const int y) const
{
    if((x < 0) || (x > size.width-1) || (y < 0) || (y > size.height-1))
    {
        throw std::out_of_range("Field::getObjectAt(x,y): coordinates out of range");
    }

    std::vector<std::shared_ptr<FieldObject>> vector;

    for(const auto& object : m_objects)
    {
        const Position pos = object->getPosition();
        if(pos.x == x && pos.y == y)
        {
            vector.push_back(object);
        }
    }
    return vector;
}

std::vector<std::shared_ptr<FieldObject> > Field::getObjects() const
{
    return m_objects;
}

std::shared_ptr<FieldObject> Field::getClosestObject(const Position &centralPoint,
                                                     const std::type_info& type) const
{
    if (m_objects.empty()) return std::shared_ptr<FieldObject>();

    double minDistance = -1;
    std::shared_ptr<FieldObject> closestObject;
    for(const auto& object : m_objects)
    {
        if(typeid(*object.get()) == type)
        {
            const double currentDistance = objectDistanceSquared(object->getPosition(), centralPoint);
            if(currentDistance < minDistance || minDistance == -1)
            {
                minDistance = currentDistance;
                closestObject = object;
            }
        }
    }
    return closestObject;
}

std::shared_ptr<FieldObject> Field::getClosestFoodObject(const Position &centralPoint,
                                                         const std::type_info& type) const
{
    if (m_objects.empty()) return std::shared_ptr<FieldObject>();

    double minDistance = -1;
    std::shared_ptr<FieldObject> closestObject;
    for(const auto& object : m_objects)
    {
        if(!object->isOccupied() && (typeid(*object.get()) == type) && (object->getFoodPoints() == object->getMaxFoodPoints()))
        {
            const double currentDistance = objectDistanceSquared(object->getPosition(), centralPoint);
            if(currentDistance < minDistance || minDistance == -1)
            {
                minDistance = currentDistance;
                closestObject = object;
            }
        }
    }
    return closestObject;
}

Size2D Field::getSize() const
{
    return size;
}

Position Field::randomPosition() const
{
    std::random_device rd;
    const std::default_random_engine generatorX(rd());
    const std::default_random_engine generatorY(rd());
    const std::uniform_int_distribution<int> distributionX(0, size.width - 1);
    const std::uniform_int_distribution<int> distributionY(0, size.height - 1);
    return Position(std::bind(distributionX, generatorX)(), std::bind(distributionY, generatorY)());
}
