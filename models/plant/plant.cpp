#include "plant.h"

Plant::Plant(const Position& pos):
    FieldObject(pos)
{
    foodPointsChanged.connect([this](const std::shared_ptr<Food>&){
        invalidated(std::static_pointer_cast<FieldObject>(IEntity::shared_from_this()));
    });
}
