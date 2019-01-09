#ifndef SHEEPBEHAVIOUR_H
#define SHEEPBEHAVIOUR_H

#include <memory>
#include <vector>
#include <chrono>

//class TickGenerator;
class BehaviourTree;
class Sheep;

struct Blackboard
{
    std::shared_ptr<Sheep> sheep;
};

class SheepBehaviour
{
public:
    SheepBehaviour();

    void addSheep(const std::shared_ptr<Sheep> &sheep);
    void start();
    void update(const std::chrono::milliseconds &tick);

private:
    std::vector<std::shared_ptr<Blackboard>> mBlackboards;
//    std::unique_ptr<TickGenerator> tickGenerator;
    BehaviourTree* mRoot;
};

#endif // SHEEPBEHAVIOUR_H
