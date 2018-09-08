#include "sheep.h"
#include <iostream>

Sheep::Sheep(Position pos):
    Animal(std::move(pos))
{
}

void Sheep::draw(const std::shared_ptr<DrawerVisitor> &drawer)
{
    std::cout<<"draw Sheep";
    drawer->drawFor(std::dynamic_pointer_cast<Sheep>(shared_from_this()));
}
