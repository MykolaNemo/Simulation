#ifndef PLANT_H
#define PLANT_H

#include "models/fieldobject.h"
#include "models/food.h"

class Plant: public FieldObject, public Food
{
protected:
    Plant(const Position &pos = Position());
};

#endif // PLANT_H
