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
    Position calculateDestinationPosition(const std::shared_ptr<FieldObject>& animalObject,
                                          const std::shared_ptr<FieldObject>& foodObject)
    {
        assert(animalObject && foodObject);

        QGraphicsItem* animalGraphics = animalObject->getGraphics();
        QGraphicsItem* foodGraphics = foodObject->getGraphics();
        assert(animalGraphics && foodGraphics);

//        QRect animalRect(animalObject->getPosition().x,
//                         animalObject->getPosition().y,
//                         animalGraphics->boundingRect().size().width(),
//                         animalGraphics->boundingRect().size().height());

//        QRect foodRect(foodObject->getPosition().x,
//                         foodObject->getPosition().y,
//                         foodGraphics->boundingRect().size().width(),
//                         foodGraphics->boundingRect().size().height());

        Position animalCenterPoint = animalObject->getPosition() +
                                        Position(animalGraphics->boundingRect().size().width()/2,
                                        animalGraphics->boundingRect().size().height()/2);
        Position foodCenterPoint = foodObject->getPosition() +
                                        Position(foodGraphics->boundingRect().size().width()/2,
                                        foodGraphics->boundingRect().size().height()/2);

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
            std::cout<<"angle:" <<angle*180.0/M_PI<<std::endl;
        }
        int x = foodCenterPoint.x + foodGraphics->boundingRect().width() * cos(angle);
        int y = foodCenterPoint.y + foodGraphics->boundingRect().height() * sin(angle);
        return Position(x,y);
//        QGraphicsItem* animalGraphics = animalObject->getGraphics();
//        QGraphicsItem* foodGraphics = foodObject->getGraphics();
//        if(!animalGraphics || !foodGraphics)
//        {
//            return animalObject->getPosition();
//        }

//        QRect animalRect(animalGraphics->pos().x(), animalGraphics->pos().y(),
//                         animalGraphics->boundingRect().size().toSize().height(),
//                         animalGraphics->boundingRect().size().toSize().width());

//        QRect foodRect(foodGraphics->pos().x(), foodGraphics->pos().y(),
//                       foodGraphics->boundingRect().size().toSize().height(),
//                       foodGraphics->boundingRect().size().toSize().width());

//        int x,y;
//        if(animalRect.center().x() <= foodRect.center().x())
//        {
//            x = foodRect.right() - animalRect.width();
//        }
//        else
//        {
//            x = foodRect.left();
//        }

//        if(animalRect.center().y() <= foodRect.center().y())
//        return Position(x,y);
    }
}

AnimalStateWalking::AnimalStateWalking(const std::shared_ptr<FieldObject> &animalObject,
                                       const std::shared_ptr<FieldObject>& destObject):
    AnimalState(),
    m_startPoint(animalObject ? animalObject->getPosition() : Position()),
//    m_destinationPoint(destObject ? destObject->getPosition() : m_startPoint),
    m_destinationPoint(calculateDestinationPosition(animalObject, destObject)),
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

    calculateDestinationPosition(currentObject, m_destinationObject);
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
