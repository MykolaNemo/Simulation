#include "plantstategrowing.h"
#include "plantstatenotgrowing.h"
#include "models/fieldobject.h"

#include <iostream>

static int growingCount = 0;

PlantStateGrowing::PlantStateGrowing():
    PlantState()
{

}

std::shared_ptr<StateAbstract> PlantStateGrowing::update(std::shared_ptr<FieldObject> &object, const Field &field)
{
    const int foodPoints = object->getFoodPoints();
    if(!object->isInUse() && (foodPoints < object->getMaxFoodPoints()))
    {
        object->setFoodPoints(foodPoints+1);
        return std::shared_ptr<StateAbstract>();
    }
    else
    {
        return std::make_shared<PlantStateNotGrowing>();
    }
}
