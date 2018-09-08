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
    if(!object->isOccupied() && (foodPoints < object->getMaxFoodPoints()))
    {
        object->setFoodPoints(foodPoints);
        return std::shared_ptr<StateAbstract>();
    }
    else
    {
        return std::make_shared<PlantStateNotGrowing>();
    }
}

std::shared_ptr<StateAbstract> PlantStateGrowing::next()
{
    return std::make_shared<PlantStateNotGrowing>();
}
