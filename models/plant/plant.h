#ifndef PLANT_H
#define PLANT_H

#include "models/fieldobject.h"
#include "boost/signals2/signal.hpp"
//#include "models/food.h"

class Plant: public FieldObject/*, public Food*/
{
public:
    void decreaseFoodPoints(int points);
    int getFoodPoints() const;
    int getMaxFoodPoints() const;
    bool isOccupied() const;
    void setAsOccupied(bool occupied);

    boost::signals2::signal<void(const std::shared_ptr<Plant>)> foodPointsChanged;
    boost::signals2::signal<void(void)> wasOccupied;

protected:
    Plant();

private:
    bool mIsOccupied = false;
};

#endif // PLANT_H
