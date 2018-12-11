#include "graphicsview.h"

#include <QDragEnterEvent>
#include <QGraphicsPixmapItem>
//#include <QGraphicsPixmapItem>
#include <QMimeData>
#include "NodeLabels/nodelabel.h"
#include "NodeGraphicsItems/sequencegraphicsitem.h"
#include "NodeGraphicsItems/fallbackgraphicsitem.h"

GraphicsView::GraphicsView(QWidget *parent)
    :QGraphicsView(parent)
{
    setRenderHints(QPainter::Antialiasing);
    setScene(new QGraphicsScene);
}

void GraphicsView::resizeEvent(QResizeEvent* event)
{
    QGraphicsView::resizeEvent(event);
    setSceneRect(rect());
}

GraphicsView::GraphicsView(QGraphicsScene *scene, QWidget *parent)
    :QGraphicsView(scene, parent)
{

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
    if(!scene())
    {
        event->ignore();
        return;
    }

    if (event->mimeData()->hasFormat("application/x-dndNode"))
    {
        QByteArray itemData = event->mimeData()->data("application/x-dndNode");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        int nodeTypeInt = 0;
        dataStream >> nodeTypeInt;
        NodeType nodeType = static_cast<NodeType>(nodeTypeInt);

        QGraphicsItem* item = nullptr;
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

        if(scene())
        {
            scene()->addItem(item);
            QPointF pos = event->pos();
            QSizeF size = item->boundingRect().size();
            item->setPos(pos.x() - size.width()/2.0, pos.y() - size.height()/2.0);
        }
        event->acceptProposedAction();
    }
    else
    {
        event->ignore();
    }
}
