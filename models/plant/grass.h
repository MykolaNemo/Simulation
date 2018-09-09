#ifndef GRASS_H
#define GRASS_H

#include "plant.h"
#include "position.h"

class GrassGraphicsItem;
class Grass: public Plant
{
public:
    static std::shared_ptr<Grass> create(const Position &pos = Position());
    QGraphicsItem *getGraphics() const override;

protected:
    explicit Grass(const Position &pos = Position());

private:
    void init();
    GrassGraphicsItem* mGraphics;
};

#endif // GRASS_H
