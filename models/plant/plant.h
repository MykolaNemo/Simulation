#ifndef PLANT_H
#define PLANT_H

#include "models/fieldobject.h"
#include "models/food.h"

class Plant: public FieldObject, public Food
{
public:
    void update(const std::shared_ptr<Field> &field, const std::chrono::milliseconds &tick) override;

protected:
    Plant(const Position &pos = Position());
};

#endif // PLANT_H
