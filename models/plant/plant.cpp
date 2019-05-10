#include "plant.h"
#include "models/plant/grassfoodcomponent.h"

Plant::Plant()
    : FieldObject()
{
    foodPointsChanged.connect([this](const std::shared_ptr<Plant>&){
        invalidated(std::static_pointer_cast<FieldObject>(IEntity::shared_from_this()));
    });

    addComponent(std::make_shared<GrassFoodComponent>());
}

void Plant::decreaseFoodPoints(int points)
{
    getComponent<GrassFoodComponent>()->decreaseAmount(points);
    /*emit*/foodPointsChanged(std::static_pointer_cast<Plant>(shared_from_this()));
}

int Plant::getFoodPoints() const
{
    return getComponent<GrassFoodComponent>()->getCurrentAmount();
}

int Plant::getMaxFoodPoints() const
{
    return getComponent<GrassFoodComponent>()->getMaximumAmount();
}

bool Plant::isOccupied() const
{
    return mIsOccupied;
}

void Plant::setAsOccupied(bool occupied)
{
    mIsOccupied = occupied;
    if(mIsOccupied)
    {
        /*emit*/ wasOccupied();
    }
}
