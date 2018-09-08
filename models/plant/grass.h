#ifndef GRASS_H
#define GRASS_H

#include "plant.h"
#include "position.h"

class Grass: public Plant
{
public:
    explicit Grass(const Position &pos = Position());
    void draw(const std::shared_ptr<DrawerVisitor> &drawer) override;
};

#endif // GRASS_H