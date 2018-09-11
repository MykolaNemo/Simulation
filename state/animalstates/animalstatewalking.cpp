#include "animalstatewalking.h"
#include "animalstateeating.h"
#include "animalstateidle.h"

#include "models/animal/animal.h"

#include <QGraphicsItem>

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

const double AnimalStateWalking::velocity = 10.0;

namespace {
    Position calculateDestinationPositionCircleContact(const std::shared_ptr<FieldObject>& animalObject,
                                          const std::shared_ptr<FieldObject>& foodObject)
    {
        assert(animalObject && foodObject);

        QGraphicsItem* animalGraphics = animalObject->getGraphics();
        QGraphicsItem* foodGraphics = foodObject->getGraphics();
        assert(animalGraphics && foodGraphics);

        QSize animalSize = animalGraphics->boundingRect().size().toSize();
        Position animalCenterPoint = animalObject->getPosition() +
                                        Position(animalSize.width()/2, animalSize.height()/2);

        QSize foodSize = foodGraphics->boundingRect().size().toSize();
        Position foodCenterPoint = foodObject->getPosition() +
                                        Position(foodSize.width()/2, foodSize.height()/2);

        double distance = sqrt(pow(abs(foodCenterPoint.x - animalCenterPoint.x),2) +
                               pow(abs(foodCenterPoint.y - animalCenterPoint.y),2));
        double xDistance = animalCenterPoint.x - foodCenterPoint.x;
        double yDistance = animalCenterPoint.y - foodCenterPoint.y;
        double angle = M_PI/2;
        if(distance != 0)
        {
            angle = acos(xDistance/distance);
            if(yDistance > 0)
            {
                angle = 2*M_PI-angle;
            }
        }

        int x = foodCenterPoint.x + static_cast<double>(foodSize.width()/2+animalSize.width()/2)*cos(angle) - animalSize.width()/2;
        int y = foodCenterPoint.y + static_cast<double>(foodSize.height()/2+animalSize.height()/2)*sin(angle) - animalSize.height()/2;

        return Position(x,y);
    }

    Position calculateDestinationPositionFromTheSide(const std::shared_ptr<FieldObject>& animalObject,
                                                     const std::shared_ptr<FieldObject>& foodObject)
    {
        assert(animalObject && foodObject);

        QGraphicsItem* animalGraphics = animalObject->getGraphics();
        QGraphicsItem* foodGraphics = foodObject->getGraphics();
        assert(animalGraphics && foodGraphics);

        QSize animalSize = animalGraphics->boundingRect().size().toSize();
        Position animalCenterPoint = animalObject->getPosition() +
                                        Position(animalSize.width()/2, animalSize.height()/2);

        QSize foodSize = foodGraphics->boundingRect().size().toSize();
        Position foodCenterPoint = foodObject->getPosition() +
                                        Position(foodSize.width()/2, foodSize.height()/2);

        int x,y;
        if(animalCenterPoint.x <= foodCenterPoint.x)
        {
            x = foodObject->getPosition().x - animalSize.width();
            y = foodCenterPoint.y - animalSize.height()/2;
        }
        else
        {
            x = foodObject->getPosition().x + foodSize.width();
            y = foodCenterPoint.y - animalSize.height()/2;
        }
        return Position(x,y);
    }
}


AnimalStateWalking::AnimalStateWalking(const std::shared_ptr<FieldObject> &animalObject,
                                       const std::shared_ptr<FieldObject>& destObject):
    AnimalState(),
    m_startPoint(animalObject ? animalObject->getPosition() : Position()),
//    m_destinationPoint(destObject ? destObject->getPosition() : m_startPoint),
    m_destinationPoint(calculateDestinationPositionFromTheSide(animalObject, destObject)),
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

    calculateDestinationPositionCircleContact(currentObject, m_destinationObject);
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
