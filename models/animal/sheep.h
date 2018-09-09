#ifndef SHEEP_H
#define SHEEP_H

#include "animal.h"

class SheepGraphicsItem;
class Sheep: public Animal
{
public:
    QGraphicsItem* getGraphics() const;
    static std::shared_ptr<Sheep> create(const Position& pos = Position());

protected:
    Sheep(Position pos = Position());

private:
    void init();
    SheepGraphicsItem* mGraphics;
};

#endif // SHEEP_H
