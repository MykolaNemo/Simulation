#ifndef ANIMALSTATEEATING_H
#define ANIMALSTATEEATING_H

#include "state/state.h"

class AnimalStateEating: public AnimalState/*State<StateEnum::Animal>*/
{
public:
    AnimalStateEating();

    ~AnimalStateEating(){}
    AnimalStateEating(const AnimalStateEating& other) = default;
    AnimalStateEating(AnimalStateEating&& other) = default;
    AnimalStateEating& operator =(const AnimalStateEating& other) = default;
    AnimalStateEating& operator =(AnimalStateEating&& other) = default;

    std::shared_ptr<StateAbstract> update() override;

private:
    void doWork();
    std::shared_ptr<StateAbstract> next() override;
};

#endif // ANIMALSTATEEATING_H
