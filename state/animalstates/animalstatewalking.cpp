#include "animalstatewalking.h"
#include "animalstateeating.h"
#include "animalstateidle.h"

#include "models/fieldobject.h"

#include <iostream>
#include <math.h>

const double AnimalStateWalking::velocity = 10.0;

namespace {
    Position calculateDestinationPosition(const std::shared_ptr<FieldObject> &animalObject,
                                          const std::shared_ptr<FieldObject>& destObject)
    {
        return Position();
    }
}

AnimalStateWalking::AnimalStateWalking(const std::shared_ptr<FieldObject> &animalObject,
                                       const std::shared_ptr<FieldObject>& destObject):
    AnimalState(),
    m_startPoint(animalObject ? animalObject->getPosition() : Position()),
    m_destinationPoint(destObject ? destObject->getPosition() : m_startPoint),
    m_totalDistance(sqrt(pow(abs(m_destinationPoint.x - m_startPoint.x),2) +
                         pow(abs(m_destinationPoint.y - m_startPoint.y),2))),
    m_lastUpdateTime(std::chrono::system_clock::now()),
    m_destinationObject(destObject)
{
    if(m_destinationObject)
    {
        m_destinationObject->setInUse(true);
        m_signalConnections.push_back(m_destinationObject->wasOccupied.connect([this](){
            m_interrupt = true;
        }));
    }
}

AnimalStateWalking::~AnimalStateWalking()
{
    for(auto connection : m_signalConnections)
    {
        connection.disconnect();
    }
}

std::shared_ptr<StateAbstract> AnimalStateWalking::update(std::shared_ptr<FieldObject> &currentObject, const Field &)
{
    if(m_interrupt)
    {
        return std::make_shared<AnimalStateIdle>();
    }

    if(m_distanceWalked != m_totalDistance)
    {
        doWork(currentObject);
    }
    else
    {
        return std::make_shared<AnimalStateEating>(m_destinationObject);
    }
    return std::shared_ptr<StateAbstract>();
}

void AnimalStateWalking::doWork(std::shared_ptr<FieldObject>& object)
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    long long microsecondsPast = std::chrono::duration_cast<std::chrono::microseconds>(now - m_lastUpdateTime).count();
    m_lastUpdateTime = now;

    m_distanceWalked += velocity*(static_cast<double>(microsecondsPast)/1000000.0);
    if(m_distanceWalked > m_totalDistance)
    {
        m_distanceWalked = m_totalDistance;
    }
    const int x = static_cast<int>(static_cast<double>(m_startPoint.x) -
                             (m_distanceWalked * static_cast<double>(m_startPoint.x - m_destinationPoint.x))/m_totalDistance);
    const int y = static_cast<int>(static_cast<double>(m_startPoint.y) -
                             (m_distanceWalked * static_cast<double>(m_startPoint.y - m_destinationPoint.y))/m_totalDistance);

    object->setPosition(Position(x,y));
}
