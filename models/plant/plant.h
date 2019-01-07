#ifndef PLANT_H
#define PLANT_H

#include "models/fieldobject.h"

class PlantState;
class StateAbstract;

class Plant: public FieldObject
{
public:
    void update(const Field &field) override;

protected:
    Plant(const Position &pos = Position());
    void createStateConnections(const std::shared_ptr<PlantState> &plantState);
    void setState(const std::shared_ptr<PlantState> &newState);

private:
    std::shared_ptr<StateAbstract> m_state;
};

#endif // PLANT_H
