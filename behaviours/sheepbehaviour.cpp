#include "sheepbehaviour.h"

#include "BTNodes/fallback.h"
#include "BTNodes/sequence.h"
#include "BTNodes/leafnodes/nearfoodcheck.h"
#include "BTNodes/leafnodes/gotofoodaction.h"
#include "BTNodes/leafnodes/ishungrycheck.h"
#include "BTNodes/leafnodes/eatfoodaction.h"
#include "BTNodes/leafnodes/idleaction.h"

SheepBehaviour::SheepBehaviour()
{
    mRoot = std::make_unique<Fallback>("Root");

    auto ensureNearFoodFallback = new Fallback("EnsureNearFood_fallback");
    ensureNearFoodFallback->addChild(new IsNearFood("IsNearFood_leafcheck"))
                 ->addChild(new GoToFood("GoToFood_leafaction"));

    auto eatSequence = new Sequence("Eat_sequence");
    eatSequence->addChild(new IsHungry("IsHungry_leaf_check"))
               ->addChild(ensureNearFoodFallback)
               ->addChild(new EatFood("EatFood_leaf_action"));

    mRoot->addChild(eatSequence);
    mRoot->addChild(new IdleAction("Idle_leaf_action"));
}

void SheepBehaviour::update(const std::chrono::milliseconds& tick,
                            std::shared_ptr<Blackboard> &blackboard)
{
    mRoot->execute(tick, blackboard);
}
