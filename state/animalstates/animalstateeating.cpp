#include "animalstateeating.h"
#include "animalstateidle.h"
#include "models/field.h"
#include "models/fieldobject.h"

#include <iostream>

static int eatingCount = 0;

AnimalStateEating::AnimalStateEating(const std::shared_ptr<FieldObject> &foodObject):
    mFoodObject(foodObject)
{
    if(mFoodObject)
    {
        mFoodObject->setOccupied(true);
    }
}

std::shared_ptr<StateAbstract> AnimalStateEating::update(FieldObject &object, const Field &field)
{
    if(eatingCount < 5)
    {
        std::cout<<"Eating update"<<std::endl;
        eatingCount++;
    }
    else
    {
        eatingCount = 0;
        if(mFoodObject)
        {
//            mFoodObject->setOccupied(false);
            mFoodObject->setEated(true);
        }
        return std::make_shared<AnimalStateIdle>();
    }
    return std::shared_ptr<StateAbstract>();
}

std::shared_ptr<StateAbstract> AnimalStateEating::next()
{
    return std::make_shared<AnimalStateIdle>();
}
