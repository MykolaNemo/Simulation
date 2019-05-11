#ifndef AISYSTEM_H
#define AISYSTEM_H

#include <vector>
#include <memory>
#include "ECS/system.h"

//class IAIComponent;
class IEntity;
class Field;

class AISystem: public ISystem
{
public:
    AISystem() = default;
    void setField(const std::shared_ptr<Field>& field);
    void update(const std::chrono::milliseconds &tickDuration, std::shared_ptr<IEntity> &entity);

private:
//    std::vector<std::shared_ptr<IAIComponent>> aiComponents;
    std::shared_ptr<Field> mField;
};

#endif // AISYSTEM_H
