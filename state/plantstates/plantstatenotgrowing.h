#ifndef PLANTSTATENOTGROWING_H
#define PLANTSTATENOTGROWING_H

#include "state/state.h"

class PlantStateNotGrowing: public PlantState/*State<StateEnum::Plant>*/
{
public:
    PlantStateNotGrowing();
    ~PlantStateNotGrowing(){}
    PlantStateNotGrowing(const PlantStateNotGrowing& other) = default;
    PlantStateNotGrowing(PlantStateNotGrowing&& other) = default;
    PlantStateNotGrowing& operator =(const PlantStateNotGrowing& other) = default;
    PlantStateNotGrowing& operator =(PlantStateNotGrowing&& other) = default;

    std::shared_ptr<StateAbstract> update() override;

private:
    void doWork();
    std::shared_ptr<StateAbstract> next() override;
};

#endif // PLANTSTATENOTGROWING_H
