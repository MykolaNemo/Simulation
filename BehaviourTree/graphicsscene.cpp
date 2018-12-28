#include "graphicsscene.h"

#include <QKeyEvent>
#include <QGraphicsItem>
#include <QDebug>
#include <QGraphicsView>

GraphicsScene::GraphicsScene(QObject *parent):
    QGraphicsScene(parent)
{
    connect(this, &QGraphicsScene::selectionChanged, [this](){
        auto selection = selectedItems();
        if(selection.size() == 1)
        {
            if(selection.front() != mLastSelection)
            {
                if(mLastSelection)
                {
                    mLastSelection->setSelected(false);
                }
                mLastSelection = selection.front();
            }
        }
        else if(selection.size() == 2)
        {
            if(mLastSelection)
            {
                mLastSelection->setSelected(false);
                selection.removeOne(mLastSelection);
            }
        }
        else
        {
            qDebug()<<"Wrong selection";
        }
    });
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


//void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
//{
//    QGraphicsScene::mousePressEvent(event);
//}

//void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
//{
//    QGraphicsScene::mouseReleaseEvent(event);
//}
