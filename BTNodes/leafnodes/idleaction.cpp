#include "idleaction.h"

#include "models/animal/animal.h"
#include "behaviours/blackboards/blackboard.h"

IdleAction::IdleAction(std::string name, BehaviourTree *parent)
    : BehaviourTree(std::move(name), parent)
{
}

BehaviourTree::ExecuteResult IdleAction::execute(const std::chrono::milliseconds &/*tick*/,
                                                 std::shared_ptr<Blackboard>& blackboard)
{
    if(!blackboard->animal)
    {
        return BehaviourTree::ExecuteResult::FAILURE;
    }
    blackboard->animal->increaseHunger(1);
    return BehaviourTree::ExecuteResult::SUCCESS;
}
