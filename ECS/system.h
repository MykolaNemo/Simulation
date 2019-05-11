#ifndef SYSTEM_H
#define SYSTEM_H

#include <chrono>
#include <memory>

class IEntity;
class ISystem
{
public:
    virtual ~ISystem() = default;
    virtual void update(const std::chrono::milliseconds& tickDuration,
                        std::shared_ptr<IEntity>& entity) = 0;
};

#endif // SYSTEM_H
