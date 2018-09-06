#include "plantstatenotgrowing.h"
#include "plantstategrowing.h"
#include <iostream>

static int notGrowingCount = 0;

PlantStateNotGrowing::PlantStateNotGrowing():
    PlantState()
//    State<StateEnum::Plant>(StateEnum::Plant::NotGrowing)
{

}

std::shared_ptr<StateAbstract> PlantStateNotGrowing::update()
{
    if(notGrowingCount < 5)
    {
        std::cout<<"Not growing update"<<std::endl;
        doWork();
        return std::shared_ptr<StateAbstract>();
    }
    else
    {
        notGrowingCount = 0;
        return next();
    }
}

void PlantStateNotGrowing::doWork()
{
    notGrowingCount++;
}

std::shared_ptr<StateAbstract> PlantStateNotGrowing::next(/*const std::shared_ptr<ThinkerInfo> &thinkerInfo*/)
{
    return std::make_shared<PlantStateGrowing>();
}
