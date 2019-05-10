#ifndef ECSENGINE_H
#define ECSENGINE_H

#include <memory>
#include <vector>
#include <type_traits>

class IEntity;
class ISystem;

class ECSEngine
{
public:
    template<class T>
    std::shared_ptr<IEntity> newEntity()
    {
        static_assert (std::is_convertible<T, IEntity>::value == std::false_type(),
                       "ECSEngine::newEntity -> type must derive from IEntity");

        auto entity = T::create();
        entities.push_back(entity);
        return entity;
    }

    void addSystem(const std::shared_ptr<ISystem>& system);

private:
    std::vector<std::shared_ptr<IEntity> > entities;
    std::vector<std::shared_ptr<ISystem> > systems;
};

#endif // ECSENGINE_H
