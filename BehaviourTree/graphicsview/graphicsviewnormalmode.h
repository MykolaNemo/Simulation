#ifndef GRAPHICSVIEWNORMALMODE_H
#define GRAPHICSVIEWNORMALMODE_H

#include "graphicsviewabstractmode.h"

class GraphicsView;

class GraphicsViewNormalMode: public GraphicsViewAbstractMode
{
public:
    GraphicsViewNormalMode(GraphicsView* view);
    GraphicsViewAbstractMode::Mode getMode() const;
};

#endif // GRAPHICSVIEWNORMALMODE_H
