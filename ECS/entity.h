#ifndef ENTITY_H
#define ENTITY_H

#include <memory>
#include <map>
#include <typeinfo>
#include <typeindex>

#include "component.h"

class IEntity
{
public:
    void addComponent(const std::shared_ptr<IComponent>& component)
    {
        components[std::type_index(typeid(*component))] = component;
    }

    template <typename T>
    std::shared_ptr<T> getComponent() const
    {
        std::type_index index(typeid(T));
        if(components.count(index) != 0)
        {
            return std::static_pointer_cast<T>(components.at(index));
        }
        else
        {
            return std::shared_ptr<T>();
        }
    }
private:
    std::map<const std::type_index, std::shared_ptr<IComponent>> components;
};

#endif // ENTITY_H
