#ifndef SYSTEM_H
#define SYSTEM_H

#include <chrono>

class ISystem
{
public:
    ISystem() = default;
    virtual ~ISystem() = default;
    virtual void update(const std::chrono::milliseconds& tickDuration) = 0;
};

#endif // SYSTEM_H
