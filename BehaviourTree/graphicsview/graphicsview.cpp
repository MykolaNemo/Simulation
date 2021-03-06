#include "graphicsview.h"

#include "NodeLabels/nodelabel.h"
#include "NodeGraphicsItems/sequencegraphicsitem.h"
#include "NodeGraphicsItems/fallbackgraphicsitem.h"
#include "NodeGraphicsItems/rootgraphicsitem.h"
#include "NodeGraphicsItems/leafgraphicsitem.h"
#include "graphicsscene.h"
#include "GraphicsItems/arrowitem.h"
#include "graphicsviewnormalmode.h"
#include "graphicsviewarrowplacemode.h"

#include <QDragEnterEvent>
#include <QGraphicsPixmapItem>
#include <QMimeData>
#include <QDebug>

GraphicsView::GraphicsView(QWidget *parent):
    QGraphicsView(parent),
    mMode(new GraphicsViewNormalMode(this))
{
    if(!mScene)
    {
        throw std::logic_error("GraphicsView::GraphicsView -> Graphics scene is null!");
    }
    setScene(mScene);
    setBackgroundBrush(QBrush(QColor(0xdd,0xdd,0xdd)));
    setRenderHints(QPainter::Antialiasing);
}

void GraphicsView::resizeEvent(QResizeEvent* event)
{
    QGraphicsView::resizeEvent(event);
    setSceneRect(rect());
}

void GraphicsView::mousePressEvent(QMouseEvent *event)
{
    auto nextMode = mMode->mousePress(event);
    setMode(nextMode);
    mScene->update(rect());
    if(mMode->getMode() != GraphicsViewAbstractMode::Mode::ArrowPlace)
    {
        QGraphicsView::mousePressEvent(event);
    }
}

void GraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    if(mMode->getMode() != GraphicsViewAbstractMode::Mode::ArrowPlace)
    {
        QGraphicsView::mouseReleaseEvent(event);
    }
}

void GraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    auto nextMode = mMode->mouseMove(event);
    setMode(nextMode);
    mScene->update(rect());

    if(mMode->getMode() != GraphicsViewAbstractMode::Mode::ArrowPlace)
    {
        QGraphicsView::mouseMoveEvent(event);
    }
}

void GraphicsView::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dndNode"))
    {
        event->acceptProposedAction();
    }
    else
    {
        event->ignore();
    }
}

void GraphicsView::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dndNode"))
    {
        event->acceptProposedAction();
    }
    else
    {
        event->ignore();
    }
}

void GraphicsView::dropEvent(QDropEvent *event)
{
    const QMimeData* mimeData = event->mimeData();
    if (!mimeData->hasFormat("application/x-dndNode"))
    {
        event->ignore();
        return;
    }

    event->acceptProposedAction();

    QByteArray itemData = mimeData->data("application/x-dndNode");
    QDataStream dataStream(&itemData, QIODevice::ReadOnly);

    int nodeTypeInt = 0;
    dataStream >> nodeTypeInt;
    auto nodeType = static_cast<NodeType>(nodeTypeInt);

    NodeGraphicsItem* item = nullptr;
    switch (nodeType)
    {
    case NodeType::Sequence:
    {
        item = new SequenceGraphicsItem();
        break;
    }
    case NodeType::Fallback:
    {
        item = new FallbackGraphicsItem();
        break;
    }
    case NodeType::Root:
    {
        item = new RootGraphicsItem();
        emit rootWasChanged(item->getTreeModel());
        break;
    }
    case NodeType::Leaf:
    {
        item = new LeafGraphicsItem();
        break;
    }
    }

    connect(item, &NodeGraphicsItem::requestArrowCreation, [this](NodeGraphicsItem* nodeItem){
        createArrowSlot(nodeItem);
    });
    mScene->addItem(item);
    const QPointF pos = event->pos();
    const QSizeF size = item->boundingRect().size();
    item->setPos(pos.x() - size.width()/2.0, pos.y() - size.height()/2.0);
}

void GraphicsView::createArrowSlot(NodeGraphicsItem* nodeItem)
{
    if(mMode->getMode() == GraphicsViewAbstractMode::Mode::Normal)
    {
        setMode(std::move(std::make_unique<GraphicsViewArrowPlaceMode>(this, nodeItem)));
    }
}

void GraphicsView::setMode(std::unique_ptr<GraphicsViewAbstractMode>&& mode)
{
    mMode = std::move(mode);
}

void GraphicsView::setMode(const GraphicsViewAbstractMode::Mode &mode)
{
    if((mode == GraphicsViewAbstractMode::Mode::None) || (mMode->getMode() == mode))
    {
        return;
    }

    switch (mode)
    {
    case GraphicsViewAbstractMode::Mode::Normal:
    {
        mMode = std::make_unique<GraphicsViewNormalMode>(this);
        break;
    }
    case GraphicsViewAbstractMode::Mode::ArrowPlace:
    {
        mMode = std::make_unique<GraphicsViewArrowPlaceMode>(this, nullptr);
        break;
    }
    default:
        break;
    }
    update();
}
