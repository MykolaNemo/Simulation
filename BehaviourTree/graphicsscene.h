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
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
//    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    QGraphicsItem* mLastSelection = nullptr;
};

#endif // GRAPHICSSCENE_H
