#ifndef AISYSTEM_H
#define AISYSTEM_H

#include <vector>
#include <memory>
#include "ECS/system.h"

class IAIComponent;
class Field;

class AISystem: public ISystem
{
public:
    AISystem() = default;
    void update(const std::chrono::milliseconds &tickDuration) override;
    void setField(const std::shared_ptr<Field>& field);

private:
    std::vector<std::shared_ptr<IAIComponent>> aiComponents;
    std::shared_ptr<Field> mField;
};

#endif // AISYSTEM_H
