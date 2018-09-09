#include "animalstateeating.h"
#include "animalstateidle.h"
#include "models/field.h"
#include "models/fieldobject.h"
#include "models/plant/grass.h"

#include <iostream>

static int eatingCount = 0;

AnimalStateEating::AnimalStateEating(const std::shared_ptr<FieldObject> &foodObject):
    mFoodObject(foodObject)
{
//    if(mFoodObject)
//    {
//        mFoodObject->setOccupied(true);
//    }
}

std::shared_ptr<StateAbstract> AnimalStateEating::update(std::shared_ptr<FieldObject> &object, const Field &field)
{
    if(mFoodObject)
    {
        std::shared_ptr<Grass> grass = std::dynamic_pointer_cast<Grass>(mFoodObject);
        if(grass && grass->getFoodPoints() > 0)
        {
            grass->setFoodPoints(grass->getFoodPoints() - 5);
            if(grass->getFoodPoints() <= 0)
            {
                mFoodObject->setOccupied(false);
                return std::make_shared<AnimalStateIdle>();
            }
            return std::shared_ptr<StateAbstract>();
        }
    }
    return std::make_shared<AnimalStateIdle>();
}

std::shared_ptr<StateAbstract> AnimalStateEating::next()
{
    return std::make_shared<AnimalStateIdle>();
}
