#ifndef SHEEP_H
#define SHEEP_H

#include "animal.h"

class Sheep: public Animal
{
public:
    Sheep(Position pos = Position());

    void draw(const std::shared_ptr<DrawerVisitor> &drawer) override;
};

#endif // SHEEP_H
