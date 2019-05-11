#include "plant.h"
#include "ECS/Components/foodcomponent.h"
#include "ECS/Components/canbeoccupiedcomponent.h"

Plant::Plant()
    : FieldObject()
{
    foodPointsChanged.connect([this](const std::shared_ptr<Plant>&){
        invalidated(std::static_pointer_cast<FieldObject>(shared_from_this()));
    });

    addComponent(std::make_shared<FoodComponent>());
    addComponent(std::make_shared<CanBeOccupiedComponent>());
}

void Plant::decreaseFoodPoints(int points)
{
    getComponent<FoodComponent>()->decreaseAmount(points);
    /*emit*/foodPointsChanged(std::static_pointer_cast<Plant>(shared_from_this()));
}

int Plant::getFoodPoints() const
{
    return getComponent<FoodComponent>()->getCurrentAmount();
}

int Plant::getMaxFoodPoints() const
{
    return getComponent<FoodComponent>()->getMaximumAmount();
}

bool Plant::isOccupied() const
{
    return getComponent<CanBeOccupiedComponent>()->isOccupied();
}

void Plant::setAsOccupied(bool occupied)
{
    getComponent<CanBeOccupiedComponent>()->setAsOccupied(occupied);
    if(occupied)
    {
        /*emit*/ wasOccupied();
    }
}
