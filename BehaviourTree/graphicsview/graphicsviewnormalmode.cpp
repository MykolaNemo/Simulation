#include "graphicsviewnormalmode.h"

#include "graphicsview.h"

GraphicsViewNormalMode::GraphicsViewNormalMode(GraphicsView* view)
{
    view->setMouseTracking(false);
}

GraphicsViewAbstractMode::Mode GraphicsViewNormalMode::getMode() const
{
    return GraphicsViewAbstractMode::Mode::Normal;
}
