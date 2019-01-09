#include "plantstategrowing.h"
#include "plantstatenotgrowing.h"
#include "models/fieldobject.h"
#include "models/plant/plant.h"

#include <iostream>

//static int growingCount = 0;

std::shared_ptr<StateAbstract> PlantStateGrowing::update(std::shared_ptr<FieldObject> &object, const Field &/*field*/)
{
    auto plant = std::dynamic_pointer_cast<Plant>(object);
    if(!plant)
    {
        return std::shared_ptr<StateAbstract>();
    }

    const int foodPoints = plant->getFoodPoints();
    if(!plant->isInUse() && (foodPoints < plant->getMaxFoodPoints()))
    {
        plant->setFoodPoints(foodPoints+1);
        return std::shared_ptr<StateAbstract>();
    }
    return std::make_shared<PlantStateNotGrowing>();
}
