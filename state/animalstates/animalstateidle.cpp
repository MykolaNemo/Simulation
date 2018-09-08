#include "animalstateidle.h"
#include <iostream>

#include <memory>
#include "state/animalstates/animalstatewalking.h"

#include "models/field.h"
#include "models/fieldobject.h"
#include "models/plant/grass.h"

static int idlingCount = 0;

std::shared_ptr<StateAbstract> AnimalStateIdle::update(std::shared_ptr<FieldObject> &object, const Field &field)
{
    if(idlingCount < 5)
    {
        idlingCount++;
    }
    else
    {
        const auto currentPosition = object->getPosition();
        const auto closestGrass = field.getClosestFoodObject(currentPosition, typeid(Grass));
        if(closestGrass)
        {
            idlingCount = 0;
            return std::make_shared<AnimalStateWalking>(currentPosition, closestGrass);
        }
    }
    return std::shared_ptr<StateAbstract>();
}

std::shared_ptr<StateAbstract> AnimalStateIdle::next()
{
    idlingCount = 0;
    return std::make_shared<AnimalStateWalking>(Position(),std::shared_ptr<FieldObject>());
}
