#include "animalstateeating.h"
#include "animalstateidle.h"
#include <iostream>

static int eatingCount = 0;

AnimalStateEating::AnimalStateEating():
    AnimalState()
//    State<StateEnum::Animal>(StateEnum::Animal::Eating)
{
}

std::shared_ptr<StateAbstract> AnimalStateEating::update()
{
    if(eatingCount < 5)
    {
        std::cout<<"Eating update"<<std::endl;
        doWork();
        return std::shared_ptr<StateAbstract>();
    }
    else
    {
        eatingCount = 0;
        return next();
    }
}

void AnimalStateEating::doWork()
{
    eatingCount++;
}

std::shared_ptr<StateAbstract> AnimalStateEating::next(/*const std::shared_ptr<ThinkerInfo> &thinkerInfo*/)
{
    return std::make_shared<AnimalStateIdle>();
}
