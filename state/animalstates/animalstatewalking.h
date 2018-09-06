#ifndef ANIMALSTATEWALKING_H
#define ANIMALSTATEWALKING_H

#include "position.h"
#include <chrono>
#include "state/state.h"

class AnimalStateWalking: public AnimalState/*State<StateEnum::Animal>*/
{
public:
    AnimalStateWalking(const Position start, const Position dest);
    ~AnimalStateWalking(){}
    AnimalStateWalking(const AnimalStateWalking& other) = default;
    AnimalStateWalking(AnimalStateWalking&& other) = default;
    AnimalStateWalking& operator =(const AnimalStateWalking& other) = default;
    AnimalStateWalking& operator =(AnimalStateWalking&& other) = default;

//    Position getPosition() const;

    std::shared_ptr<StateAbstract> update() override;

private:
    void doWork();
    std::shared_ptr<StateAbstract> next() override;

    const Position m_startPoint;
    const Position m_destinationPoint;
    const double m_totalDistance = 0.0;

//    double velocity = 5;

    std::chrono::system_clock::time_point m_lastUpdateTime;
//    double m_distanceWalked = 0.0;
//    Position m_currentPosition;
};

#endif // ANIMALSTATEWALKING_H
