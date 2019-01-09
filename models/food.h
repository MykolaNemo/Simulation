#ifndef FOOD_H
#define FOOD_H

#include "boost/signals2/signal.hpp"
#include <memory>
#include "virtual_enable_shared_from_this.h"

class Food: public virtual_enable_shared_from_this<Food>
{
public:
    void setFoodPoints(int foodPoints);
    int getMaxFoodPoints() const;
    int getFoodPoints() const;

    boost::signals2::signal<void(const std::shared_ptr<Food>)> foodPointsChanged;

private:
    const int mMaxFoodPoints = 250;
    int mFoodPoints = mMaxFoodPoints;
};

#endif // FOOD_H
