#include "mainwindow.h"
#include <QApplication>

#include "BehaviourNodes/sequence.h"
#include "BehaviourNodes/fallback.h"
#include "BehaviourNodes/leaf.h"
#include "BehaviourNodes/tickgenerator.h"
#include "sheep.h"

int main(int argc, char *argv[])
{
    auto notHungrySheep = std::make_shared<Sheep>();
    auto hungrySheep = std::make_shared<Sheep>();
    hungrySheep->hungry = true;

    TickGenerator* tickGenerator1 = new TickGenerator(notHungrySheep);
    TickGenerator* tickGenerator2 = new TickGenerator(hungrySheep);
    BehaviourTree* fallback1 = new Fallback("fallback1");
    BehaviourTree* leaf1 = new Leaf("leaf1");
    fallback1->addChild(leaf1);
    BehaviourTree* sequence1 = new Sequence("sequence1");
    BehaviourTree* leaf2 = new Leaf("leaf2");
    sequence1->addChild(leaf2);

    tickGenerator2->addTree(std::shared_ptr<BehaviourTree>(fallback1));
    tickGenerator2->addTree(std::shared_ptr<BehaviourTree>(sequence1));
//    tickGenerator1->addTree(std::shared_ptr<BehaviourTree>(fallback1));
//    tickGenerator1->addTree(std::shared_ptr<BehaviourTree>(sequence1));
    tickGenerator2->start();

    QApplication a(argc, argv);
    MainWindow w;
    QObject::connect(&w, &QMainWindow::close, [&tickGenerator1](){
        tickGenerator1->stop();
    });
    QObject::connect(&w, &QMainWindow::close, [&tickGenerator2](){
        tickGenerator2->stop();
    });
    w.show();
    return QApplication::exec();
}
