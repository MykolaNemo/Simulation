#include "animalstatethinktowalk.h"
#include "animalstatewalking.h"
#include "models/field.h"
#include "models/plant/grass.h"

#include <memory>
#include <iostream>

AnimalStateThinkToWalk::AnimalStateThinkToWalk(const Position& currentPosition,
                                               const std::shared_ptr<Field> &field):
    mField(field),
    mCurrentPosition(currentPosition)
{
}

std::shared_ptr<StateAbstract> AnimalStateThinkToWalk::update(FieldObject &object, const Field &field)
{
    std::cout<<"Thinking where to go..."<<std::endl;
    return next();
}

std::shared_ptr<StateAbstract> AnimalStateThinkToWalk::next()
{
    auto closest = mField->getClosestUnoccupiedObject(mCurrentPosition, typeid(Grass));
    return std::make_shared<AnimalStateWalking>(mCurrentPosition, closest);
}
