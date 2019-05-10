#include "entity.h"
#include <algorithm>

using ComponentPair = std::pair<const std::type_index, std::shared_ptr<IComponent>>;
EntityId IEntity::mLastId = 0;

IEntity::IEntity()
{
    std::lock_guard<std::mutex> lock(idMutex);
    mLastId++;
    mId = mLastId;
}

EntityId IEntity::getId() const
{
    return mId;
}

void IEntity::addComponent(const std::shared_ptr<IComponent> &component)
{
    components[std::type_index(typeid(*component))] = component;
}

bool IEntity::removeComponent(const std::shared_ptr<IComponent> &component)
{
    auto it = std::find_if(components.begin(), components.end(),
                        [&component](const ComponentPair& pair)->bool
    {
        return (pair.second == component);
    });

    if(it != components.end())
    {
        components.erase(it);
    }
    return false;
}
