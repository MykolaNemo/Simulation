#ifndef MOVINGSYSTEM_H
#define MOVINGSYSTEM_H

#include <vector>
#include "../system.h"
#include "../Components/positioncomponent.h"
#include "../Components/velocitycomponent.h"

class MovingSystem: public ISystem
{
public:
    MovingSystem() = default;
    ~MovingSystem() override = default;

    void update(const std::chrono::milliseconds &tickDuration) override;

private:
    std::vector<IPositionComponent> positionComponents;
    std::vector<IVelocityComponent> velocityComponents;
};

#endif // MOVINGSYSTEM_H
