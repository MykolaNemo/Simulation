#ifndef GRAPHICSVIEWNORMALMODE_H
#define GRAPHICSVIEWNORMALMODE_H

#include "graphicsviewabstractmode.h"

class GraphicsView;

class GraphicsViewNormalMode: public GraphicsViewAbstractMode
{
public:
    GraphicsViewNormalMode(GraphicsView* view);
    GraphicsViewAbstractMode::Mode getMode() const override;

private:
    GraphicsView* mView = nullptr;
};

#endif // GRAPHICSVIEWNORMALMODE_H
