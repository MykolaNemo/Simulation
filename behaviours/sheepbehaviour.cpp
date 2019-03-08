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

    auto goEatFallback = new Fallback("Go_eat_fallback");
    goEatFallback->addChild(new NearFoodCheck("NearFoodCheck"))
                 ->addChild(new GoToFoodAction("GoToFoodAction"));

    auto eatSequence = new Sequence("Eat_sequence");
    eatSequence->addChild(goEatFallback)
               ->addChild(new IsHungryCheck("IsHungryCheck"))
               ->addChild(new EatFoodAction("EatFoodAction"));

    mRoot->addChild(eatSequence);
    mRoot->addChild(new IdleAction("IdleAction"));
}

void SheepBehaviour::update(const std::chrono::milliseconds& tick,
                            std::shared_ptr<Blackboard> &blackboard)
{
    mRoot->execute(tick, blackboard);
}
