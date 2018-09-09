#ifndef ANIMALSTATEIDLE_H
#define ANIMALSTATEIDLE_H

#include "state/state.h"

class AnimalStateIdle: public AnimalState
{
public:
    AnimalStateIdle() = default;

    ~AnimalStateIdle(){}
    AnimalStateIdle(const AnimalStateIdle& other) = default;
    AnimalStateIdle(AnimalStateIdle&& other) = default;
    AnimalStateIdle& operator =(const AnimalStateIdle& other) = default;
    AnimalStateIdle& operator =(AnimalStateIdle&& other) = default;
    std::shared_ptr<StateAbstract> update(std::shared_ptr<FieldObject> &object, const Field &field) override;

private:
    void doWork();
};

#endif // ANIMALSTATEIDLE_H
