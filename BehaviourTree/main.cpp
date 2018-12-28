#include "mainwindow.h"
#include <QApplication>

#include "BehaviourNodes/sequence.h"
#include "BehaviourNodes/selector.h"
#include "BehaviourNodes/leaf.h"
#include "BehaviourNodes/repeater.h"
#include "BehaviourNodes/tickgenerator.h"

#include <iostream>
#include <thread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    BehaviourTree* treeRoot = new Sequence("Root");
    BehaviourTree* treeRoot2 = treeRoot;

    BehaviourTree* firstNode = new Selector("Selector");
    firstNode->addChild(new Leaf("Leaf_Selector_1"));
    firstNode->addChild(new Leaf("Leaf_Selector_2"));
    firstNode->addChild(new Leaf("Leaf_Selector_3"));

    treeRoot->addChild(firstNode);
    treeRoot->addChild(new Leaf("Leaf_Sequence_1"));
    treeRoot->addChild(new Leaf("Leaf_Sequence_2"));
    treeRoot->addChild(new Leaf("Leaf_Sequence_3"));

    TickGenerator generator;
    generator.addTree(std::shared_ptr<BehaviourTree>(treeRoot));

    generator.start();

//    MainWindow w;
//    w.show();

    return QApplication::exec();
}
