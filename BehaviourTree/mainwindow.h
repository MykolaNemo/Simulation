#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Tree;

namespace Ui {
class MainWindow;
}

class QGraphicsScene;
class QGraphicsView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void generateTree();
    void onRootChanged(const std::shared_ptr<Tree>& treeRoot);
    void traverseTree(const std::shared_ptr<Tree> &tree);

    Ui::MainWindow *ui;
    std::shared_ptr<Tree> mTreeRoot;
};

#endif // MAINWINDOW_H
