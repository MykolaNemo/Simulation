#ifndef GRAPHICSVIEWARROWPLACEMODE_H
#define GRAPHICSVIEWARROWPLACEMODE_H

#include "graphicsviewabstractmode.h"

class ArrowItem;
class GraphicsView;
class NodeGraphicsItem;

class GraphicsViewArrowPlaceMode: public GraphicsViewAbstractMode
{
public:
    GraphicsViewArrowPlaceMode(GraphicsView* view, NodeGraphicsItem* startNodeItem);
    GraphicsViewAbstractMode::Mode getMode() const override;
    Mode mousePress(QMouseEvent* event) override;
    Mode mouseMove(QMouseEvent* event) override;

private:
    ArrowItem* mArrow = nullptr;
    GraphicsView* mView = nullptr;
};

#endif // GRAPHICSVIEWARROWPLACEMODE_H
