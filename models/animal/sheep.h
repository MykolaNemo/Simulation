#ifndef SHEEP_H
#define SHEEP_H

#include "animal.h"
#include "behaviours/sheepbehaviour.h"

class SheepGraphicsItem;
class Sheep: public Animal
{
public:
    static std::shared_ptr<Sheep> create(const Position& pos = Position());
    void update(const std::shared_ptr<Field> &field, const std::chrono::milliseconds &tick) override;
    QGraphicsItem* getGraphics() const override;
    int getHungerThreshold() const override;
//    int getVelocity() const override;

protected:
    Sheep(const Position pos = Position());

private:
    void init();

//    const int mHungerThreshold = 5;
//    const int mSpeed = 10;

    static SheepBehaviour mBehaviour;
    std::shared_ptr<Blackboard> mBlackboard;
};

#endif // SHEEP_H
