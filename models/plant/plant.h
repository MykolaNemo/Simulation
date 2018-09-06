#ifndef PLANT_H
#define PLANT_H

#include "models/fieldobject.h"

class PlantState;

class Plant: public FieldObject
{
public:
    void update() override;

protected:
    Plant(const Position &pos = Position());
    void createStateConnections(const std::shared_ptr<PlantState> &plantState);
    void setState(const std::shared_ptr<PlantState> &newState);
};

#endif // PLANT_H
