#ifndef SHEEP_H
#define SHEEP_H

#include "animal.h"
#include "behaviours/sheepbehaviour.h"

class SheepGraphicsItem;
class Sheep: public Animal
{
public:
    static std::shared_ptr<Sheep> create();
    void update(const std::shared_ptr<Field> &field, const std::chrono::milliseconds &tick) override;
    QGraphicsItem* getGraphics() const override;
    std::shared_ptr<SheepBehaviour> getBehaviour() const;

protected:
    Sheep() = default;

private:
    void init();
    static const std::shared_ptr<SheepBehaviour> mBehaviour;
};

#endif // SHEEP_H
