#include "eatfoodaction.h"

#include "behaviours/blackboards/blackboard.h"
#include "models/animal/animal.h"
#include "models/plant/plant.h"
//#include <iostream>

EatFoodAction::EatFoodAction(std::string name, BehaviourTree *parent)
    : BehaviourTree(std::move(name), parent)
{
}

BehaviourTree::ExecuteResult EatFoodAction::execute(const std::chrono::milliseconds &,
                                                    std::shared_ptr<Blackboard>& blackboard)
{
//    std::cout<<getName();
    if(!blackboard->animal || !blackboard->food)
    {
//        std::cout<<": FAILURE"<<std::endl;
        return BehaviourTree::ExecuteResult::FAILURE;
    }
    blackboard->food->decreaseFoodPoints(1);
    blackboard->animal->decreaseHunger(1);

    if(blackboard->food->getFoodPoints() == 0)
    {
        blackboard->food->setAsOccupied(false);
        blackboard->food = std::shared_ptr<Plant>();
//        std::cout<<": SUCCESS"<<std::endl;
        return BehaviourTree::ExecuteResult::SUCCESS;
    }
//    std::cout<<": RUNNING"<<std::endl;
    return BehaviourTree::ExecuteResult::RUNNING;
}
