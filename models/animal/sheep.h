#ifndef SHEEP_H
#define SHEEP_H

#include "animal.h"

class ThinkerInfo;

class Sheep: public Animal
{
public:
    Sheep(Position pos = Position());

//    void think(const std::shared_ptr<ThinkerInfo> &thinkerInfo) override;
    void draw(const std::shared_ptr<DrawerVisitor> &drawer) override;
//    void transferToNextState(const std::shared_ptr<Field>& field) = 0;
};

#endif // SHEEP_H
