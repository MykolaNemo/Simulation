#include "plant.h"

Plant::Plant(const Position& pos):
    FieldObject(pos)
{
    foodPointsChanged.connect([this](const std::shared_ptr<Food>&){
        invalidated(FieldObject::shared_from_this());
    });
}
