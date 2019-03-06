#ifndef BLACKBOARD_H
#define BLACKBOARD_H

#include <memory>

class FieldObject;
class Plant;
class Field;

struct Blackboard
{
    Blackboard() = default;
    virtual ~Blackboard(){}
    std::shared_ptr<FieldObject> actor;
    std::shared_ptr<Plant> food;
    std::shared_ptr<Field> field;
    int sheepSpeed = 10;
};

#endif // BLACKBOARD_H
