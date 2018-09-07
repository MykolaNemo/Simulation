#ifndef ANIMALSTATETHINKTOWALK_H
#define ANIMALSTATETHINKTOWALK_H

#include "state/state.h"
#include "position.h"

class AnimalStateThinkToWalk: public AnimalState
{
public:
    AnimalStateThinkToWalk(const Position &currentPosition, const std::shared_ptr<Field>& field);

    std::shared_ptr<StateAbstract> update(FieldObject &object, const Field &field) override;
    std::shared_ptr<StateAbstract> next() override;

private:
    const std::shared_ptr<Field> mField;
    const Position mCurrentPosition;
};
#endif // ANIMALSTATETHINKTOWALK_H
