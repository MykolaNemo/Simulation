#ifndef ANIMAL_H
#define ANIMAL_H

#include "boost/signals2/signal.hpp"

#include "models/fieldobject.h"

class StateAbstract;
class AnimalState;

class Animal : public FieldObject
{
public:
    void grow();
//    void update(const Field &field, const std::chrono::milliseconds& tick);

    int getHunger() const;
    void increaseHunger(int amount);
    void decreaseHunger(int amount);
    virtual int getHungerThreshold() const = 0;

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
