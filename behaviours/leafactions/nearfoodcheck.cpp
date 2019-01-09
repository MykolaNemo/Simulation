#include "nearfoodcheck.h"
#include <QRect>

NearFoodCheck::NearFoodCheck(std::string name, BehaviourTree *parent):
    BehaviourTree(name, parent)
{
}

BehaviourTree::ExecuteResult NearFoodCheck::execute(const std::chrono::milliseconds &)
{
    if((eaterRect.left() == foodRect.right() + 1) || (foodRect.left() == eaterRect.right() + 1))
    {
        return BehaviourTree::ExecuteResult::SUCCESS;
    }
    return BehaviourTree::ExecuteResult::FAILURE;
}

void NearFoodCheck::setFoodRect(const QRect &rect)
{
    foodRect = rect;
}

void NearFoodCheck::setEaterRect(const QRect &rect)
{
    eaterRect = rect;
}
