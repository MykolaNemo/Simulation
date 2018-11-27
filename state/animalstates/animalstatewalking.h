#ifndef ANIMALSTATEWALKING_H
#define ANIMALSTATEWALKING_H

#include "position.h"
#include "state/state.h"

#include <chrono>
#include <memory>
#include <vector>
#include "boost/signals2/signal.hpp"

class Animal;
class AnimalStateWalking: public AnimalState/*State<StateEnum::Animal>*/
{
public:
    AnimalStateWalking(const std::shared_ptr<FieldObject> &animalObject,
                       const std::shared_ptr<FieldObject> &destObject);
    ~AnimalStateWalking() override;
    AnimalStateWalking(const AnimalStateWalking& other) = default;
    AnimalStateWalking(AnimalStateWalking&& other) = default;
    AnimalStateWalking& operator =(const AnimalStateWalking& other) = default;
    AnimalStateWalking& operator =(AnimalStateWalking&& other) = default;

    std::shared_ptr<StateAbstract> update(std::shared_ptr<FieldObject> &currentObject, const Field &) override;

private:
    void doWork(std::shared_ptr<FieldObject> &object);

    static const double velocity;
    const Position m_startPoint;
    const Position m_destinationPoint;
    const double m_totalDistance = 0.0;
    double m_distanceWalked = 0.0;
    bool m_interrupt = false;

    std::chrono::system_clock::time_point m_lastUpdateTime;
    std::shared_ptr<FieldObject> m_destinationObject;

    std::vector<boost::signals2::connection> m_signalConnections;
};

#endif // ANIMALSTATEWALKING_H
