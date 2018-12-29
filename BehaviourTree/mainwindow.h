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

signals:
    void treeGenerated(const std::shared_ptr<Tree>& tree);

private:
    void onRootChanged(const std::shared_ptr<Tree>& treeRoot);
    std::string traverseTree(const std::shared_ptr<Tree> &tree, std::string &generatedString);

    std::string tickGeneratorString(const std::string &name) const;
    std::string sequenceString(const std::string &name) const;
    std::string fallbackString(const std::string &name) const;
    std::string leafString(const std::string &name) const;
    std::string childToParentNodeString(const std::string &parentName, const std::string &childName) const;
    std::string treeToTickGeneratorString(const std::string &generatorName, const std::string &childName) const;

    Ui::MainWindow *ui;
    std::shared_ptr<Tree> mTreeRoot;
};

#endif // MAINWINDOW_H
