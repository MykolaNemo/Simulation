#include "sheepstrategy.h"
#include "state/animalstates/animalstateidle.h"
#include "state/animalstates/animalstatewalking.h"
#include "state/animalstates/animalstateeating.h"
#include "models/animal/animal.h"

SheepStrategy::SheepStrategy(const std::shared_ptr<Sheep> &sheep):
    mSheep(sheep)
{

}

void SheepStrategy::nextState(const std::shared_ptr<AnimalStateIdle> &previousState)
{
//    auto field = thinkerInfo->getField();
//    auto closest = field->getClosestObject(mSheep->getPosition(), typeid(Grass));
//    auto newState = std::make_shared<AnimalStateWalking>(mSheep->getPosition(), closest->getPosition());
//    mSheep->setState(newState);
}

void SheepStrategy::nextState(const std::shared_ptr<AnimalStateWalking> &previousState)
{
//    mSheep->setState(std::make_shared<AnimalStateEating>());
}

void SheepStrategy::nextState(const std::shared_ptr<AnimalStateEating> &previousState)
{
//    mSheep->setState(std::make_shared<AnimalStateIdle>());
}
