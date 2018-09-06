#include "animalstatewalking.h"
#include "animalstateeating.h"
#include <iostream>
#include <math.h>

static int walkingCount = 0;

AnimalStateWalking::AnimalStateWalking(const Position start, const Position dest):
    AnimalState(),
    m_startPoint(std::move(start)),
    m_destinationPoint(std::move(dest)),
    m_totalDistance(sqrt(pow(abs(m_destinationPoint.x - m_startPoint.x),2) +
                         pow(abs(m_destinationPoint.y - m_startPoint.y),2))),
    m_lastUpdateTime(std::chrono::system_clock::now())
{
}

std::shared_ptr<StateAbstract> AnimalStateWalking::update()
{
    if(walkingCount < 5)
    {
        std::cout<<"Walking update"<<std::endl;
        doWork();
        return std::shared_ptr<StateAbstract>();
    }
    else
    {
        walkingCount = 0;
        return next();
    }
}

void AnimalStateWalking::doWork()
{
    walkingCount++;

    //    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    //    long long microsecondsPast = std::chrono::duration_cast<std::chrono::microseconds>(now - m_lastUpdateTime).count();
    //    m_lastUpdateTime = now;

    //    m_distanceWalked += velocity*(static_cast<double>(microsecondsPast)/1000000.0);
    //    if(m_distanceWalked > m_totalDistance)
    //    {
    //        m_distanceWalked = m_totalDistance;
    //    }
    //    m_currentPosition.x = static_cast<int>(static_cast<double>(m_startPoint.x) -
    //            (m_distanceWalked * static_cast<double>(m_startPoint.x - m_destinationPoint.x))/m_totalDistance);
    //    m_currentPosition.y = static_cast<int>(static_cast<double>(m_startPoint.y) -
    //            (m_distanceWalked * static_cast<double>(m_startPoint.y - m_destinationPoint.y))/m_totalDistance);

    //    updated();
}

//Position AnimalStateWalking::getPosition() const
//{
//    return m_currentPosition;
//}

std::shared_ptr<StateAbstract> AnimalStateWalking::next(/*const std::shared_ptr<ThinkerInfo> &thinkerInfo*/)
{
    return std::make_shared<AnimalStateEating>();
}
