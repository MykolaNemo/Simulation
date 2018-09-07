#include "plantstatenotgrowing.h"
#include "plantstategrowing.h"
#include <iostream>

static int notGrowingCount = 0;

std::shared_ptr<StateAbstract> PlantStateNotGrowing::update(FieldObject &object, const Field &field)
{
    if(notGrowingCount < 5)
    {
        notGrowingCount++;
    }
    else
    {
        notGrowingCount = 0;
        return std::make_shared<PlantStateGrowing>();
    }
    return std::shared_ptr<StateAbstract>();
}

std::shared_ptr<StateAbstract> PlantStateNotGrowing::next(/*const std::shared_ptr<ThinkerInfo> &thinkerInfo*/)
{
    return std::make_shared<PlantStateGrowing>();
}
