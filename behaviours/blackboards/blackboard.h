#ifndef BLACKBOARD_H
#define BLACKBOARD_H

#include <memory>

class IEntity;
class Field;

struct Blackboard
{
    Blackboard() = default;
    virtual ~Blackboard(){}
    std::shared_ptr<IEntity> actor;
    std::shared_ptr<IEntity> plant;
    std::shared_ptr<Field> field;
};

#endif // BLACKBOARD_H
