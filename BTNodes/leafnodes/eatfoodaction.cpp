#include "eatfoodaction.h"

#include "models/animal/sheep.h"
#include "models/plant/plant.h"
#include "behaviours/blackboards/blackboard.h"
#include <iostream>

EatFoodAction::EatFoodAction(std::string name, BehaviourTree *parent)
    : BehaviourTree(std::move(name), parent)
{

}

BehaviourTree::ExecuteResult EatFoodAction::execute(const std::chrono::milliseconds &,
                                                    std::shared_ptr<Blackboard>& blackboard)
{
    std::cout<<getName();
    if(!blackboard->actor || !blackboard->food)
    {
        return BehaviourTree::ExecuteResult::FAILURE;
    }
    blackboard->food->setFoodPoints(blackboard->food->getFoodPoints()-1);
    std::shared_ptr<Sheep> sheep = std::static_pointer_cast<Sheep>(blackboard->actor);
    sheep->decreaseHunger(1);

    if(blackboard->food->getFoodPoints() == 0)
    {
        blackboard->food = std::shared_ptr<Plant>();
        std::cout<<": SUCCESS"<<std::endl;
        return BehaviourTree::ExecuteResult::SUCCESS;
    }
    std::cout<<": RUNNING"<<std::endl;
    return BehaviourTree::ExecuteResult::RUNNING;
}
