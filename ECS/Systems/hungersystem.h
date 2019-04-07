#ifndef HUNGERSYSTEM_H
#define HUNGERSYSTEM_H

#include <vector>
#include "../system.h"
#include "../Components/hungercomponent.h"

class HungerSystem: public ISystem
{
public:
    HungerSystem() = default;
    ~HungerSystem() override = default;

    void update(const std::chrono::milliseconds &tickDuration) override;

private:
    std::vector<IHungerComponent> hungerComponents;
};

#endif // HUNGERSYSTEM_H
