#include "mainwindow.h"
#include <QApplication>

#include "BehaviourNodes/sequence.h"
#include "BehaviourNodes/fallback.h"
#include "BehaviourNodes/leaf.h"
#include "BehaviourNodes/tickgenerator.h"

#include "BehaviourNodes/own/ishungrycheck.h"
#include "BehaviourNodes/own/eataction.h"
#include "sheep.h"

int main(int argc, char *argv[])
{
    auto notHungrySheep = std::make_shared<Sheep>();
    auto hungrySheep = std::make_shared<Sheep>();
    hungrySheep->hungry = true;

    TickGenerator* tickGenerator = new TickGenerator();
    BehaviourTree* sequence = new Sequence("Sequence");
    BehaviourTree* isHungryLeaf1 = new IsHungryCheck("IsHungry_Leaf", hungrySheep);
    sequence->addChild(isHungryLeaf1);
    BehaviourTree* eatLeaf = new EatFoodAction("Eat_Leaf", hungrySheep);
    sequence->addChild(eatLeaf);
    tickGenerator->addTree(std::shared_ptr<BehaviourTree>(sequence));
    tickGenerator->start();

    QApplication a(argc, argv);
    MainWindow w;
    QObject::connect(&w, &QMainWindow::close, [&tickGenerator](){
        tickGenerator->stop();
    });
    w.show();
    return QApplication::exec();
}
