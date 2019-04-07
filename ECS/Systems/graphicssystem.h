#ifndef GRAPHICSSYSTEM_H
#define GRAPHICSSYSTEM_H

#include <vector>
#include "../system.h"
#include "../Components/graphicscomponent.h"

class GraphicsSystem : public ISystem
{
public:
    GraphicsSystem() = default;
    ~GraphicsSystem() override = default;
    void update(const std::chrono::milliseconds &tickDuration) override;

private:
    std::vector<IGraphicsComponent> graphicsComponents;
};

#endif // GRAPHICSSYSTEM_H
