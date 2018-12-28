#include "graphicsviewarrowplacemode.h"
#include "NodeGraphicsItems/nodegraphicsitem.h"
#include "graphicsview.h"
#include "GraphicsItems/arrowitem.h"
#include "tree.h"

#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QGraphicsItem>

GraphicsViewArrowPlaceMode::GraphicsViewArrowPlaceMode(GraphicsView* view, NodeGraphicsItem* startNodeItem):
    mView(view)
{
    if(!mView || !mView->scene())
    {
        throw std::logic_error("GraphicsViewArrowPlaceMode::GraphicsViewArrowPlaceMode -> view or scene is null!");
    }
    mView->setMouseTracking(true);

    auto scene = mView->scene();
    mArrow = new ArrowItem(startNodeItem, nullptr);
    scene->addItem(mArrow);

    mArrow->setEndPoint(mArrow->mapFromScene(mView->mapToScene(mView->mapFromGlobal(QCursor::pos()))));
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
            if(nodeItemIt == itemsList.end())
            {
                event->accept();
                return GraphicsViewAbstractMode::Mode::None;
            }

            auto endNodeItem = qgraphicsitem_cast<NodeGraphicsItem*>(*nodeItemIt);
            const auto startNodeItem = mArrow->getStartItem();
            if (endNodeItem &&
               (endNodeItem != startNodeItem) &&
               (endNodeItem->getTreeModel()->getType() != Tree::NodeType::TickGenerator))
            {
                if(mArrow->setEndItem(endNodeItem))
                {
                    mArrow = nullptr;
                    return GraphicsViewAbstractMode::Mode::Normal;
                }
            }
            event->accept();
        }
    }
    return GraphicsViewAbstractMode::Mode::None;
}

GraphicsViewAbstractMode::Mode GraphicsViewArrowPlaceMode::mouseMove(QMouseEvent* event)
{
    if(mArrow)
    {
        mArrow->setEndPoint(mArrow->mapFromScene(mView->mapToScene(mView->mapFromGlobal(QCursor::pos()))));
        event->accept();
    }
    return GraphicsViewAbstractMode::Mode::None;
}
