#include "gotofoodaction.h"
#include <iostream>

GoToFoodAction::GoToFoodAction(std::string name, BehaviourTree *parent):
    BehaviourTree(name, parent)
{

}

BehaviourTree::ExecuteResult GoToFoodAction::execute(const std::chrono::milliseconds &tick,
                                                     std::shared_ptr<Blackboard>& blackboard)
{
    std::cout<<getName()<<std::endl;
    long long microsecondsPast = std::chrono::duration_cast<std::chrono::microseconds>(tick).count();

//    m_distanceWalked += velocity*(static_cast<double>(microsecondsPast)/1000000.0);
//    if(m_distanceWalked > m_totalDistance)
//    {
//        m_distanceWalked = m_totalDistance;
//    }
//    const auto x = static_cast<int>(static_cast<double>(m_startPoint.x) -
//                                    (m_distanceWalked * static_cast<double>(m_startPoint.x - m_destinationPoint.x))/m_totalDistance);
//    const auto y = static_cast<int>(static_cast<double>(m_startPoint.y) -
//                                    (m_distanceWalked * static_cast<double>(m_startPoint.y - m_destinationPoint.y))/m_totalDistance);

//    object->setPosition(Position(x,y));
    return BehaviourTree::ExecuteResult::RUNNING;
}
