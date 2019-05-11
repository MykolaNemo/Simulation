#ifndef ENTITY_H
#define ENTITY_H

#include <memory>
#include <map>
#include <typeinfo>
#include <typeindex>
#include <mutex>

#include "component.h"

using EntityId = unsigned int;
using ComponentMap = std::map<const std::type_index, std::shared_ptr<IComponent>>;

class IEntity: public std::enable_shared_from_this<IEntity>
{
    IEntity(const IEntity&) = default;
    IEntity& operator=(const IEntity&) = default;

protected:
    IEntity();

public:
    EntityId getId() const;

    void addComponent(const std::shared_ptr<IComponent>& component);
    bool removeComponent(const std::shared_ptr<IComponent>& component);

    template <typename T>
    std::shared_ptr<T> getComponent() const
    {
        if(components.count(typeid(T)) != 0)
        {
            return std::static_pointer_cast<T>(components.at(typeid(T)));
        }
        else
        {
            return std::shared_ptr<T>();
        }
    }

private:
    ComponentMap components;
    EntityId mId;
    static EntityId mLastId;
    std::mutex idMutex;
};

#endif // ENTITY_H
