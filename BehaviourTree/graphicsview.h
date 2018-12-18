#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include "graphicsscene.h"

class NodeGraphicsItem;
class ArrowItem;

class GraphicsView: public QGraphicsView
{
    Q_OBJECT
    enum class Mode
    {
        Normal = 0,
        Arrow
    };
public:
    explicit GraphicsView(QWidget *parent = nullptr);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

private:
    void createArrowSlot(NodeGraphicsItem* nodeItem);
    void setMode(const Mode& mode);

    GraphicsScene* mScene = new GraphicsScene();
    Mode mMode = Mode::Normal;
    ArrowItem* mArrowForPlacing = nullptr;
};

#endif // GRAPHICSVIEW_H
