#ifndef ECSENGINE_H
#define ECSENGINE_H

#include <memory>
#include <vector>
#include <map>
#include <type_traits>
#include <future>
#include <set>

class IEntity;
class ISystem;

using Priority = unsigned int;

class ECSEngine
{
public:
    ~ECSEngine();
    void start();
    void stop();
    void addSystem(const std::shared_ptr<ISystem>& system, Priority priority);

    template<class T>
    std::shared_ptr<IEntity> newEntity()
    {
        static_assert (std::is_convertible<T, IEntity>::value == std::false_type(),
                       "ECSEngine::newEntity -> type must derive from IEntity");

        auto entity = T::create();
        entities.push_back(entity);
        return entity;
    }

private:
    void mainLoop();

    std::vector<std::shared_ptr<IEntity> > entities;
    std::vector<std::pair<Priority, std::shared_ptr<ISystem>>> systems;

    std::future<void> m_future;
    std::atomic_bool m_interrupt = {false};
};

#endif // ECSENGINE_H
