#include "graphicsviewnormalmode.h"

#include "graphicsview.h"

GraphicsViewNormalMode::GraphicsViewNormalMode(GraphicsView* view):
    mView(view)
{
    if(!mView)
    {
        throw std::logic_error("GraphicsViewNormalMode::GraphicsViewNormalMode -> view is null!");
    }
    mView->setMouseTracking(false);
}

GraphicsViewAbstractMode::Mode GraphicsViewNormalMode::getMode() const
{
    return GraphicsViewAbstractMode::Mode::Normal;
}
