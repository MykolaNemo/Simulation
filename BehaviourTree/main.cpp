#include "mainwindow.h"
#include <QApplication>

#include "tree.h"
#include <iostream>

void TraverseTree(Tree* tree)
{
    if(!tree) return;

    std::cout<<tree->getValue()<<std::endl;
    for(Tree* child : tree->getChildren())
    {
        TraverseTree(child);
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    Tree* treeRoot = new Tree();
//    Tree* firstNode = new Tree(1);
//    firstNode->addChild(new Tree(5));
//    treeRoot->addChild(firstNode);
//    treeRoot->addChild(new Tree(2));
//    treeRoot->addChild(new Tree(3));
//    treeRoot->addChild(new Tree(4));

//    TraverseTree(treeRoot);

    MainWindow w;
    w.show();

    return QApplication::exec();
}
