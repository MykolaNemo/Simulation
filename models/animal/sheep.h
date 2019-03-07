#ifndef SHEEP_H
#define SHEEP_H

#include "animal.h"
#include "behaviours/sheepbehaviour.h"

class SheepGraphicsItem;
class Sheep: public Animal
{
public:
    QGraphicsItem* getGraphics() const override;
    static std::shared_ptr<Sheep> create(const Position& pos = Position());
    int getHungerThreshold() const override;
    void update(const std::shared_ptr<Field> &field, const std::chrono::milliseconds &tick) override;

protected:
    Sheep(const Position pos = Position());

private:
    void init();

    SheepGraphicsItem* mGraphics = nullptr;
    const int mHungerThreshold = 5;

    static SheepBehaviour mBehaviour;
    std::shared_ptr<Blackboard> mBlackboard;
};

#endif // SHEEP_H
