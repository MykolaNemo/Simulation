#include "sheepbehaviour.h"

#include "behaviours/tickgenerator.h"
#include "behaviours/sequence.h"
#include "behaviours/fallback.h"
#include "behaviours/invertor.h"
#include "behaviours/leafactions/ishungrycheck.h"
#include "behaviours/leafactions/nearfoodcheck.h"
#include "models/animal/sheep.h"
#include "behaviours/leafactions/gotofoodaction.h"
//#include "behaviours/tickgenerator.h"

SheepBehaviour::SheepBehaviour()
//    tickGenerator(std::make_unique<TickGenerator>())
{
    mRoot = new Fallback("Root");

    auto goEatFallback = new Fallback("Go_eat_fallback");
    goEatFallback->addChild(new NearFoodCheck("NearFoodCheck"))
                 ->addChild(new GoToFoodAction("GoToFoodAction"));

    auto eatSequence = new Sequence("Eat_sequence");
    eatSequence->addChild(goEatFallback)
             ->addChild(new IsHungryCheck("IsHungryLeaf2"));
//             ->addChild(new Leaf("EAT_STATELeaf6"));

    mRoot->addChild(eatSequence);
//    mRoot->addChild(new Leaf("IDLE_STATE"));
}

void SheepBehaviour::addSheep(const std::shared_ptr<Sheep> &sheep)
{
    auto blackboard = std::make_shared<Blackboard>();
    blackboard->sheep = sheep;
    mBlackboards.push_back(blackboard);
}

void SheepBehaviour::start()
{
//    tickGenerator->start(mBlackboards);
}

void SheepBehaviour::update(const std::chrono::milliseconds& tick)
{
    mRoot->execute(tick);
}
