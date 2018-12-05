#include "mainwindow.h"
#include <QApplication>

#include "BehaviourNodes/sequence.h"
#include "BehaviourNodes/selector.h"
#include "BehaviourNodes/leaf.h"
#include "BehaviourNodes/repeater.h"
#include <iostream>
#include <thread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    BehaviourTree* repeater = new Repeater("Repeater");
    BehaviourTree* treeRoot = new Sequence("Root");
    repeater->addChild(treeRoot);

    BehaviourTree* firstNode = new Selector("Selector");
    firstNode->addChild(new Leaf("Leaf_Selector_1"));
    firstNode->addChild(new Leaf("Leaf_Selector_2"));
    firstNode->addChild(new Leaf("Leaf_Selector_3"));

    treeRoot->addChild(firstNode);
    treeRoot->addChild(new Leaf("Leaf_Sequence_1"));
    treeRoot->addChild(new Leaf("Leaf_Sequence_2"));
    treeRoot->addChild(new Leaf("Leaf_Sequence_3"));

    repeater->execute();

    MainWindow w;
    w.show();

    delete repeater;
    return QApplication::exec();
}
