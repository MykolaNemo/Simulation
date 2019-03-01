#include "nearfoodcheck.h"
#include <QRect>
#include <iostream>
#include "behaviours/blackboards/blackboard.h"

NearFoodCheck::NearFoodCheck(std::string name, BehaviourTree *parent):
    BehaviourTree(name, parent)
{
}

BehaviourTree::ExecuteResult NearFoodCheck::execute(const std::chrono::milliseconds &,
                                                    std::shared_ptr<Blackboard>& blackboard)
{
    std::cout<<getName()<<std::endl;
//    if((eaterRect.left() == foodRect.right() + 1) || (foodRect.left() == eaterRect.right() + 1))
//    {
//        return BehaviourTree::ExecuteResult::SUCCESS;
//    }
    QRect eaterRect = blackboard->actor;
    QRect foodRect;
    if((eaterRect.left() == foodRect.right() + 1) || (foodRect.left() == eaterRect.right() + 1))
    {
        return BehaviourTree::ExecuteResult::SUCCESS;
    }
    return BehaviourTree::ExecuteResult::FAILURE;
}

//void NearFoodCheck::setFoodRect(const QRect &rect)
//{
//    foodRect = rect;
//}

//void NearFoodCheck::setEaterRect(const QRect &rect)
//{
//    eaterRect = rect;
//}