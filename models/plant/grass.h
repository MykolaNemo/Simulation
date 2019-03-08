#ifndef GRASS_H
#define GRASS_H

#include "plant.h"
#include "position.h"

class GrassGraphicsItem;
class Grass: public Plant
{
public:
    static std::shared_ptr<Grass> create(const Position &pos = Position());
    QGraphicsItem *getGraphics() const override;
    void update(const std::shared_ptr<Field> &, const std::chrono::milliseconds &) override;

protected:
    explicit Grass(const Position &pos = Position());

private:
    void init();
    GrassGraphicsItem* mGraphics = nullptr;
};

#endif // GRASS_H
