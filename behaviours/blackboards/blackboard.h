#ifndef BLACKBOARD_H
#define BLACKBOARD_H

#include <memory>

class Animal;
class Plant;
class Field;

struct Blackboard
{
    Blackboard() = default;
    virtual ~Blackboard(){}
    std::shared_ptr<Animal> animal;
    std::shared_ptr<Plant> plant;
    std::shared_ptr<Field> field;
};

#endif // BLACKBOARD_H
