#ifndef PLANTSTATEGROWING_H
#define PLANTSTATEGROWING_H

#include "state/state.h"

class PlantStateGrowing: public PlantState/*State<StateEnum::Plant>*/
{
public:
    PlantStateGrowing();
    ~PlantStateGrowing(){}
    PlantStateGrowing(const PlantStateGrowing& other) = default;
    PlantStateGrowing(PlantStateGrowing&& other) = default;
    PlantStateGrowing& operator =(const PlantStateGrowing& other) = default;
    PlantStateGrowing& operator =(PlantStateGrowing&& other) = default;

    std::shared_ptr<StateAbstract> update(FieldObject &object, const Field &field) override;

private:
    void doWork();
    std::shared_ptr<StateAbstract> next() override;
};

#endif // PLANTSTATEGROWING_H
