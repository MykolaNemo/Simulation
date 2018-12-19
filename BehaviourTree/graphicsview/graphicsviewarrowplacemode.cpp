#include "graphicsviewarrowplacemode.h"
#include "NodeGraphicsItems/nodegraphicsitem.h"
#include "graphicsview.h"
#include "GraphicsItems/arrowitem.h"

#include <QMouseEvent>
#include <QGraphicsView>
#include <QGraphicsItem>

GraphicsViewArrowPlaceMode::GraphicsViewArrowPlaceMode(GraphicsView* view, NodeGraphicsItem* startNodeItem):
    mView(view)
{
    if(!mView && !mView->scene()) return;

    mView->setMouseTracking(true);
    QPoint cursorPos = QCursor::pos();
    QPointF scenePoint = mView->mapToScene(mView->mapFromGlobal(cursorPos));
    mArrow = new ArrowItem(startNodeItem, nullptr);
    mArrow->setEndPoint(scenePoint);
    mView->scene()->addItem(mArrow);
}

GraphicsViewAbstractMode::Mode GraphicsViewArrowPlaceMode::getMode() const
{
    return GraphicsViewAbstractMode::Mode::ArrowPlace;
}

GraphicsViewAbstractMode::Mode GraphicsViewArrowPlaceMode::mousePress(QMouseEvent* event)
{
    if(!event || !mView)
    {
        return GraphicsViewAbstractMode::Mode::None;
    }

    if(event->buttons().testFlag(Qt::RightButton))
    {
        if(mArrow)
        {
            mView->scene()->removeItem(mArrow);
            delete mArrow;
            mArrow = nullptr;
        }
        return GraphicsViewAbstractMode::Mode::Normal;
    }
    else if(event->buttons().testFlag(Qt::LeftButton))
    {
        if(mArrow)
        {
            auto nodeItemLambda = [](QGraphicsItem* item)->bool{
                return qgraphicsitem_cast<NodeGraphicsItem*>(item);
            };
            auto itemsList = mView->items(event->pos()).toStdList();
            auto nodeItemIt = std::find_if(itemsList.begin(), itemsList.end(), nodeItemLambda);
            if(nodeItemIt != itemsList.end())
            {
                auto nodeItem = qgraphicsitem_cast<NodeGraphicsItem*>(*nodeItemIt);
                if(nodeItem != mArrow->getStartItem())
                {
                    if(mArrow->setEndItem(nodeItem))
                    {
                        mArrow = nullptr;
                        return GraphicsViewAbstractMode::Mode::Normal;
                    }
                }
                event->accept();
            }
        }
    }
    return GraphicsViewAbstractMode::Mode::None;
}

GraphicsViewAbstractMode::Mode GraphicsViewArrowPlaceMode::mouseMove(QMouseEvent* event)
{
    if(mArrow)
    {
        mArrow->setEndPoint(mView->mapToScene(mView->mapFromGlobal(QCursor::pos())));
        event->accept();
    }
    return GraphicsViewAbstractMode::Mode::None;
}
