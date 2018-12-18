#include "graphicsview.h"

#include "NodeLabels/nodelabel.h"
#include "NodeGraphicsItems/sequencegraphicsitem.h"
#include "NodeGraphicsItems/fallbackgraphicsitem.h"
#include "graphicsscene.h"
#include "GraphicsItems/arrowitem.h"

#include <QDragEnterEvent>
#include <QGraphicsPixmapItem>
#include <QMimeData>
#include <QDebug>

GraphicsView::GraphicsView(QWidget *parent)
    :QGraphicsView(parent)
{
    if(!mScene)
    {
        throw std::logic_error("GraphicsView::GraphicsView -> Graphics scene is null!");
    }
    setRenderHints(QPainter::Antialiasing);
    setScene(mScene);
}

void GraphicsView::resizeEvent(QResizeEvent* event)
{
    QGraphicsView::resizeEvent(event);
    setSceneRect(rect());
}

void GraphicsView::mousePressEvent(QMouseEvent *event)
{
    if(mMode == Mode::Arrow)
    {
        if(event->buttons().testFlag(Qt::RightButton))
        {
            if(mArrowForPlacing)
            {
                mScene->removeItem(mArrowForPlacing);
                delete mArrowForPlacing;
            }
            mArrowForPlacing = nullptr;
            setMode(Mode::Normal);
            mScene->update(rect());
        }
        else if(event->buttons().testFlag(Qt::LeftButton))
        {
            if(mArrowForPlacing)
            {
                auto nodeItemLambda = [](QGraphicsItem* item)->bool{
                    return qgraphicsitem_cast<NodeGraphicsItem*>(item);
                };
                auto itemsList = items(event->pos()).toStdList();
                auto nodeItemIt = std::find_if(itemsList.begin(), itemsList.end(), nodeItemLambda);
                if(nodeItemIt != itemsList.end())
                {
                    mArrowForPlacing->setEndItem(qgraphicsitem_cast<NodeGraphicsItem*>(*nodeItemIt));
                    mArrowForPlacing = nullptr;
                    setMode(Mode::Normal);
                    mScene->update(rect());
                }
            }
            return;
        }
    }
    QGraphicsView::mousePressEvent(event);
}

void GraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    if((mMode == Mode::Arrow) && mArrowForPlacing)
    {
        QPoint cursorPos = QCursor::pos();
        QPointF scenePoint = mapToScene(mapFromGlobal(cursorPos));
        mArrowForPlacing->setEndPoint(scenePoint);
        mScene->update(rect());
        event->accept();
        return;
    }
    QGraphicsView::mouseMoveEvent(event);
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
    NodeType nodeType = static_cast<NodeType>(nodeTypeInt);

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
    if(mMode == Mode::Normal)
    {
        QPoint cursorPos = QCursor::pos();
        QPointF scenePoint = mapToScene(mapFromGlobal(cursorPos));

        ArrowItem* arrow = new ArrowItem(nodeItem, nullptr);
        arrow->setEndPoint(scenePoint);
        mScene->addItem(arrow);

        mArrowForPlacing = arrow;
        setMode(Mode::Arrow);
    }
}

void GraphicsView::setMode(const GraphicsView::Mode &mode)
{
    if(mMode != mode)
    {
        mMode = mode;
        if(mMode == Mode::Normal)
        {
            setMouseTracking(false);
        }
        else if(mMode == Mode::Arrow)
        {
            setMouseTracking(true);
        }
        update();
    }
}
