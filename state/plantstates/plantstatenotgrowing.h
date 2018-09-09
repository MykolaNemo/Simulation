#ifndef PLANTSTATENOTGROWING_H
#define PLANTSTATENOTGROWING_H

#include "state/state.h"

class PlantStateNotGrowing: public PlantState/*State<StateEnum::Plant>*/
{
public:
    PlantStateNotGrowing() = default;
    ~PlantStateNotGrowing() = default;
    PlantStateNotGrowing(const PlantStateNotGrowing& other) = default;
    PlantStateNotGrowing(PlantStateNotGrowing&& other) = default;
    PlantStateNotGrowing& operator =(const PlantStateNotGrowing& other) = default;
    PlantStateNotGrowing& operator =(PlantStateNotGrowing&& other) = default;

    std::shared_ptr<StateAbstract> update(std::shared_ptr<FieldObject> &object, const Field &field) override;

private:
    void doWork();
};

#endif // PLANTSTATENOTGROWING_H
