#ifndef ANIMALSTRATEGY_H
#define ANIMALSTRATEGY_H

#include <memory>

class Sheep;
class AnimalStateIdle;
class AnimalStateWalking;
class AnimalStateEating;

class SheepStrategy
{
public:
    explicit SheepStrategy(const std::shared_ptr<Sheep>& sheep);
    void nextState(const std::shared_ptr<AnimalStateIdle>& previousState);
    void nextState(const std::shared_ptr<AnimalStateWalking>& previousState);
    void nextState(const std::shared_ptr<AnimalStateEating>& previousState);

private:
    std::shared_ptr<Sheep> mSheep;
};

#endif // ANIMALSTRATEGY_H
