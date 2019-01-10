#ifndef SHEEPBLACKBOARD_H
#define SHEEPBLACKBOARD_H

#include <memory>
#include "blackboard.h"

class Sheep;

struct SheepBlackboard: public Blackboard
{
    SheepBlackboard() = default;
    ~SheepBlackboard() override {}
    std::shared_ptr<Sheep> sheep;
};

#endif // SHEEPBLACKBOARD_H
