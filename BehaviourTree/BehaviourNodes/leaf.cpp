#include "leaf.h"
#include <iostream>
#include <string>
#include "sheep.h"

Leaf::Leaf(BehaviourTree *parent)
    : Leaf(0,"",parent)
{
}

Leaf::Leaf(std::string name, BehaviourTree *parent)
    : Leaf(0,std::move(name),parent)
{
}

Leaf::Leaf(int value, std::string name, BehaviourTree *parent)
    : BehaviourTree(value, std::move(name), parent)
{
}

BehaviourTree::ExecuteResult Leaf::execute(const std::chrono::milliseconds &tick, std::shared_ptr<Sheep> &sheep)
{
    std::cout<<getName()<<std::endl;
    if(sheep->hungry)
    {
        std::cout<<"-------\nhungry\n-------"<<std::endl;
    }
    else
    {
        std::cout<<"-----------\nnot hungry\n-----------"<<std::endl;
    }
    return ExecuteResult::SUCCESS;
}

void Leaf::addChild(BehaviourTree* /*child*/)
{

}

void Leaf::removeChild(BehaviourTree* /*child*/)
{

}

std::vector<BehaviourTree *> Leaf::getChildren() const
{
    return std::vector<BehaviourTree*>();
}
