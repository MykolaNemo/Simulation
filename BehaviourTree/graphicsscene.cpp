#include "graphicsscene.h"

#include <QKeyEvent>
#include <QGraphicsItem>

GraphicsScene::GraphicsScene(QObject *parent):
    QGraphicsScene(parent)
{

}

void GraphicsScene::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Delete)
    {
        for(auto item : selectedItems())
        {
            this->removeItem(item);
            delete item;
        }
    }
    QGraphicsScene::keyPressEvent(event);
}


