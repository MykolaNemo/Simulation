#ifndef STATE_H
#define STATE_H

#include "boost/signals2/signal.hpp"
#include "visitors/thinkervisitor.h"

#include <memory>

//template<typename... Args>
//struct TypeList {
//    static constexpr int size{ sizeof... (Args) };
//};

//using StateTypeList = TypeList<AnimalStateEnum, PlantStateEnum>;

class FieldObject;
class Field;

class StateAbstract
{
public:
    virtual std::shared_ptr<StateAbstract> update() = 0;
//    boost::signals2::signal<void(void)> nextStateRequest;

protected:
    StateAbstract() = default;
    virtual std::shared_ptr<StateAbstract> next() = 0;
    virtual ~StateAbstract(){}
    StateAbstract(const StateAbstract& other) = default;
    StateAbstract(StateAbstract&& other) = default;
    StateAbstract& operator =(const StateAbstract& other) = default;
    StateAbstract& operator =(StateAbstract&& other) = default;
};

class AnimalState: public StateAbstract
{
protected:
    AnimalState() = default;
    virtual ~AnimalState(){}
    AnimalState(const AnimalState& other) = default;
    AnimalState(AnimalState&& other) = default;
    AnimalState& operator =(const AnimalState& other) = default;
    AnimalState& operator =(AnimalState&& other) = default;
};

class PlantState: public StateAbstract
{
protected:
    PlantState() = default;
    virtual ~PlantState(){}
    PlantState(const PlantState& other) = default;
    PlantState(PlantState&& other) = default;
    PlantState& operator =(const PlantState& other) = default;
    PlantState& operator =(PlantState&& other) = default;
};

#endif // STATE_H
