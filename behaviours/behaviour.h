#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#include <memory>
#include <chrono>
#include "BTNodes/behaviourtree.h"

struct Blackboard;
class IBehaviour
{
public:
    virtual ~IBehaviour() = default;
    virtual void update(const std::chrono::milliseconds &tick,
                        std::shared_ptr<Blackboard>& blackboard) = 0;
};

#endif // BEHAVIOUR_H
