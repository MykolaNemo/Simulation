#ifndef BLACKBOARD_H
#define BLACKBOARD_H

#include <memory>
class FieldObject;

struct Blackboard
{
    Blackboard() = default;
    virtual ~Blackboard(){}
    std::shared_ptr<FieldObject> actor;
};

#endif // BLACKBOARD_H
