#include "ecsengine.h"

void ECSEngine::addSystem(const std::shared_ptr<ISystem> &system)
{
    if(std::find(systems.begin(), systems.end(), system) == systems.end())
    {
        systems.push_back(system);
    }
}
