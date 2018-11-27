#ifndef ANIMALSTATEEATING_H
#define ANIMALSTATEEATING_H

#include "state/state.h"

class AnimalStateEating: public AnimalState/*State<StateEnum::Animal>*/
{
public:
    AnimalStateEating(std::shared_ptr<FieldObject> foodObject);
    ~AnimalStateEating() override = default;
    AnimalStateEating(const AnimalStateEating& other) = default;
    AnimalStateEating(AnimalStateEating&& other) = default;
    AnimalStateEating& operator =(const AnimalStateEating& other) = default;
    AnimalStateEating& operator =(AnimalStateEating&& other) = default;

    std::shared_ptr<StateAbstract> update(std::shared_ptr<FieldObject> &object, const Field &field) override;

private:
    std::shared_ptr<FieldObject> mFoodObject;
};

#endif // ANIMALSTATEEATING_H
