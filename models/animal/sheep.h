#ifndef SHEEP_H
#define SHEEP_H

#include "animal.h"
#include "behaviours/sheepbehaviour.h"

class SheepGraphicsItem;
struct SheepBlackboard;
class Sheep: public Animal
{
public:
    QGraphicsItem* getGraphics() const;
    static std::shared_ptr<Sheep> create(const Position& pos = Position());
    int getHungerThreshold() const override;
    void update(const Field& field, const std::chrono::milliseconds &tick) override;

protected:
    Sheep(Position pos = Position());

private:
    void init();
    SheepGraphicsItem* mGraphics = nullptr;
    const int mHungerThreshold = 5;

    static SheepBehaviour mBehaviour;
    std::shared_ptr<SheepBlackboard> mBlackboard;
};

#endif // SHEEP_H
