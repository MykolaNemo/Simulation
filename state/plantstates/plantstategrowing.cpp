#include "plantstategrowing.h"
#include "plantstatenotgrowing.h"
#include <iostream>

static int growingCount = 0;

PlantStateGrowing::PlantStateGrowing():
    PlantState()
//    State<StateEnum::Plant>(StateEnum::Plant::Growing)
{

}

std::shared_ptr<StateAbstract> PlantStateGrowing::update(FieldObject &object, const Field &field)
{
    if(growingCount < 5)
    {
//        std::cout<<"Growing update"<<std::endl;
        doWork();
        return std::shared_ptr<StateAbstract>();
    }
    else
    {
        growingCount = 0;
//        nextStateRequest();
        return next();
    }
}

void PlantStateGrowing::doWork()
{
    growingCount++;
}

std::shared_ptr<StateAbstract> PlantStateGrowing::next()
{
    return std::make_shared<PlantStateNotGrowing>();
}
