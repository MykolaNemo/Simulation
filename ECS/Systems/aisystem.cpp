#include "aisystem.h"
#include "ECS/Components/aicomponent.h"
#include "behaviours/blackboards/blackboard.h"

void AISystem::update(const std::chrono::milliseconds &tickDuration)
{
    for(auto& component : aiComponents)
    {
        auto behaviour = component->getBehaviour();
        auto blackboard = component->getBlackboard();
        blackboard->field = mField;
        behaviour->update(tickDuration, blackboard);
    }
}

void AISystem::setField(const std::shared_ptr<Field> &field)
{
    mField = field;
}
