#ifndef ANIMAL_H
#define ANIMAL_H

#include <boost/signals2/signal.hpp>

#include "models/fieldobject.h"
#include "state/state.h"

class StateAbstract;

class Animal : public FieldObject
{
public:
    void grow();
    void update(const Field &field);

    int getHunger() const;

protected:
    Animal(const Position& _position = Position());
    void createStateConnections(const std::shared_ptr<AnimalState> &animalState);
    void setState(const std::shared_ptr<AnimalState>& newState);

private:
    int m_age = 0;//days
    int hunger = 0;
    std::shared_ptr<StateAbstract> m_state;
};

#endif // ANIMAL_H
