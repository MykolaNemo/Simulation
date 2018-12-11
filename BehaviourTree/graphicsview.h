#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>

class GraphicsView: public QGraphicsView
{
public:
    explicit GraphicsView(QWidget *parent = nullptr);
    explicit GraphicsView(QGraphicsScene *scene, QWidget *parent = nullptr);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
};

#endif // GRAPHICSVIEW_H
