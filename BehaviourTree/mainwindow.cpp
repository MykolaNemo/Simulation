#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tree.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->generateButton, &QPushButton::clicked, this, &MainWindow::generateTree);
    connect(ui->graphicsView, &GraphicsView::rootWasChanged, this, &MainWindow::onRootChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generateTree()
{
    if(mTreeRoot)
    {
        traverseTree(mTreeRoot);
    }
}

void MainWindow::traverseTree(const std::shared_ptr<Tree>& tree)
{
    if(tree)
    {
        switch (tree->getType())
        {
        case Tree::NodeType::TickGenerator:
        {
            qDebug()<<"TickGenerator";
            break;
        }
        case Tree::NodeType::Sequence:
        {
            qDebug()<<"Sequence";
            break;
        }
        case Tree::NodeType::Fallback:
        {
            qDebug()<<"Fallback";
            break;
        }
        case Tree::NodeType::Leaf:
        {
            qDebug()<<"Leaf";
            break;
        }
        }
        for(const auto& child : tree->getChildren())
        {
            traverseTree(child);
        }
    }
}

void MainWindow::onRootChanged(const std::shared_ptr<Tree>& treeRoot)
{
    mTreeRoot = treeRoot;
}
