#ifndef DRAWERVISITOR_H
#define DRAWERVISITOR_H

#include <memory>

class QGraphicsItem;
class Scene;
class Sheep;
class Grass;

class DrawerVisitor
{
public:
    DrawerVisitor(const std::shared_ptr<Scene> &scene);
    void drawFor(const std::shared_ptr<Sheep> &sheep);
    void drawFor(const std::shared_ptr<Grass> &grass);

    QGraphicsItem* getGraphicsItem() const;

private:
    std::shared_ptr<Scene> mScene;
    QGraphicsItem* mLastGraphicsItem;
};

#endif // DRAWERVISITOR_H
