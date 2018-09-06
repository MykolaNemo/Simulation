#ifndef CANTHINK_H
#define CANTHINK_H

#include <memory>
#include "visitors/thinkervisitor.h"

class CanThink
{
public:
    virtual void think(const std::shared_ptr<ThinkerInfo>& thinkerInfo) = 0;
};

#endif // CANTHINK_H
