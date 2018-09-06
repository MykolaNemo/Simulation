#ifndef CANBEDRAWN_H
#define CANBEDRAWN_H

#include <memory>
#include "visitors/drawervisitor.h"

class CanBeDrawn
{
public:
    virtual void draw(const std::shared_ptr<DrawerVisitor>& drawer) = 0;
};

#endif // CANBEDRAWN_H
