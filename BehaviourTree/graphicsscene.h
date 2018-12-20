#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>

class QMouseEvent;

class GraphicsScene: public QGraphicsScene
{
public:
    GraphicsScene(QObject *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // GRAPHICSSCENE_H
