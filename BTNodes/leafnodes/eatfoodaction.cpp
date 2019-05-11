#include "eatfoodaction.h"

#include "ECS/Components/hungercomponent.h"
#include "ECS/Components/foodcomponent.h"
#include "ECS/Components/canbeoccupiedcomponent.h"
#include "behaviours/blackboards/blackboard.h"
#include "models/animal/animal.h"
#include "models/plant/plant.h"

EatFood::EatFood(std::string name, BehaviourTree *parent)
    : BehaviourTree(std::move(name), parent)
{
}

BehaviourTree::ExecuteResult EatFood::execute(const std::chrono::milliseconds &,
                                                    std::shared_ptr<Blackboard>& blackboard)
{
    if(!blackboard->actor || !blackboard->plant)
    {
        return BehaviourTree::ExecuteResult::FAILURE;
    }
    auto foodComponent = blackboard->plant->getComponent<FoodComponent>();
    foodComponent->decreaseAmount(1);
    blackboard->actor->getComponent<HungerComponent>()->decreaseHunger(1);

    if(foodComponent->getCurrentAmount() == 0)
    {
        blackboard->plant->getComponent<CanBeOccupiedComponent>()->setAsOccupied(false);
        blackboard->plant = std::shared_ptr<Plant>();
        return BehaviourTree::ExecuteResult::SUCCESS;
    }
    return BehaviourTree::ExecuteResult::RUNNING;
}
