#include "mainwindow.h"
#include <QApplication>

#include "BehaviourNodes/sequence.h"
#include "BehaviourNodes/fallback.h"
#include "BehaviourNodes/leaf.h"
#include "BehaviourNodes/tickgenerator.h"

int main(int argc, char *argv[])
{
//    BehaviourTree* treeRoot = new Sequence("Root");
//    treeRoot->addChild(new Leaf("Leaf_Sequence_1"));
//    treeRoot->addChild(new Leaf("Leaf_Sequence_2"));
//    treeRoot->addChild(new Leaf("Leaf_Sequence_3"));

//    BehaviourTree* firstNode = new Fallback("Selector");
//    firstNode->addChild(new Leaf("Leaf_Selector_1"));
//    firstNode->addChild(new Leaf("Leaf_Selector_2"));
//    firstNode->addChild(new Leaf("Leaf_Selector_3"));

//    treeRoot->addChild(firstNode);

//    TickGenerator* tickGenerator = new TickGenerator();
//    tickGenerator.addTree(std::shared_ptr<BehaviourTree>(treeRoot));
    TickGenerator* tickGenerator = new TickGenerator();
    BehaviourTree* fallback1 = new Fallback();
    BehaviourTree* sequence1 = new Sequence();
    fallback1->addChild(sequence1);
    BehaviourTree* sequence2 = new Sequence();
    fallback1->addChild(sequence2);
    BehaviourTree* sequence3 = new Sequence();
    fallback1->addChild(sequence3);
    tickGenerator->addTree(std::shared_ptr<BehaviourTree>(fallback1));
    BehaviourTree* sequence4 = new Sequence();
    tickGenerator->addTree(std::shared_ptr<BehaviourTree>(sequence4));
    BehaviourTree* fallback2 = new Fallback();
    tickGenerator->addTree(std::shared_ptr<BehaviourTree>(fallback2));
    tickGenerator->start();


    QApplication a(argc, argv);
    MainWindow w;
    QObject::connect(&w, &QMainWindow::close, [&tickGenerator](){
        tickGenerator->stop();
    });
//    QObject::connect(&w, &QMainWindow::treeGenerated, [&generator](const std::shared_ptr<Tree>& tree){
//    });
    w.show();
    return QApplication::exec();
}
