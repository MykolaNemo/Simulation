#include "leaf.h"
#include <iostream>
#include <string>

Leaf::Leaf(BehaviourTree *parent)
    : Leaf(0,"",parent)
{
}

Leaf::Leaf(std::string name, BehaviourTree *parent)
    : Leaf(0,name,parent)
{
}

Leaf::Leaf(int value, std::string name, BehaviourTree *parent)
    : BehaviourTree(value, name, parent)
{
}

BehaviourTree::ExecuteResult Leaf::execute()
{
    std::cout<<getName()<<std::endl;
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
