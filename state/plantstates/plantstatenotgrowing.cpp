#include "plantstatenotgrowing.h"
#include "plantstategrowing.h"

#include "models/fieldobject.h"

#include <iostream>

//static int notGrowingCount = 0;

std::shared_ptr<StateAbstract> PlantStateNotGrowing::update(std::shared_ptr<FieldObject> &object,
                                                            [[maybe_unused]] const Field &field)
{
    if(!object->isInUse() && (object->getFoodPoints() <= 0))
    {
        return std::make_shared<PlantStateGrowing>();
    }
    return std::shared_ptr<StateAbstract>();
}
