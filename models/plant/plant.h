#ifndef PLANT_H
#define PLANT_H

#include "models/fieldobject.h"
#include "models/food.h"

class PlantState;
class StateAbstract;

class Plant: public FieldObject, public Food
{
public:
    void update(const std::shared_ptr<Field> &field, const std::chrono::milliseconds &tick) override;

protected:
    Plant(const Position &pos = Position());
    void createStateConnections(const std::shared_ptr<PlantState> &plantState);
    void setState(const std::shared_ptr<PlantState> &newState);

private:
    std::shared_ptr<StateAbstract> m_state;
};

#endif // PLANT_H
