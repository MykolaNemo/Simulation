#include "idleaction.h"

#include <iostream>
#include "models/animal/sheep.h"
#include "behaviours/blackboards/blackboard.h"

IdleAction::IdleAction(std::string name, BehaviourTree *parent)
    : BehaviourTree(std::move(name), parent)
{

}

BehaviourTree::ExecuteResult IdleAction::execute(const std::chrono::milliseconds &,
                                                 std::shared_ptr<Blackboard>& blackboard)
{
    std::cout<<getName()<<": ";
    std::shared_ptr<Sheep> sheep = std::static_pointer_cast<Sheep>(blackboard->actor);
    sheep->increaseHunger(1);
    std::cout<<"SUCCESS"<<std::endl;
    return BehaviourTree::ExecuteResult::SUCCESS;
}
