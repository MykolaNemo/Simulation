#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include "graphicsscene.h"
#include "graphicsviewabstractmode.h"
#include <memory>

class NodeGraphicsItem;
class ArrowItem;
class Tree;

class GraphicsView: public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphicsView(QWidget *parent = nullptr);

signals:
    void rootWasChanged(const std::shared_ptr<Tree>& treeRoot);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

private:
    void createArrowSlot(NodeGraphicsItem* nodeItem);
    void setMode(std::unique_ptr<GraphicsViewAbstractMode>&& mode);
    void setMode(const GraphicsViewAbstractMode::Mode& mode);

    GraphicsScene* mScene = new GraphicsScene();
    std::unique_ptr<GraphicsViewAbstractMode> mMode;
};

#endif // GRAPHICSVIEW_H
