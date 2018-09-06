#include "animalstateidle.h"
#include <iostream>

#include <memory>
#include "state/animalstates/animalstatewalking.h"

#include "models/field.h"
#include "models/fieldobject.h"
#include "models/plant/grass.h"

static int idlingCount = 0;

std::shared_ptr<StateAbstract> AnimalStateIdle::update()
{
    if(idlingCount < 5)
    {
        std::cout<<"Idling..."<<std::endl;
        doWork();
        return std::shared_ptr<StateAbstract>();
    }
    else
    {
        return next();
    }
}

void AnimalStateIdle::doWork()
{
    idlingCount++;
}

std::shared_ptr<StateAbstract> AnimalStateIdle::next()
{
    idlingCount = 0;
    return std::make_shared<AnimalStateWalking>(Position(),Position());
}
