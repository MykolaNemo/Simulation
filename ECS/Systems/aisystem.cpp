#include "aisystem.h"
#include "ECS/entity.h"
#include "ECS/Components/aicomponent.h"
#include "behaviours/blackboards/blackboard.h"

#include <iostream>

void AISystem::update(const std::chrono::milliseconds &tickDuration,
                      std::shared_ptr<IEntity>& entity)
{
    if(!entity) return;

    auto aiComponent = entity->getComponent<AIComponent>();
    if(!aiComponent) return;

    auto behaviour = aiComponent->getBehaviour();
    auto blackboard = aiComponent->getBlackboard();
    if(!behaviour || !blackboard) return;

    blackboard->field = mField;
    behaviour->update(tickDuration, blackboard);
}

void AISystem::setField(const std::shared_ptr<Field> &field)
{
    mField = field;
}
