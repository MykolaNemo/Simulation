#ifndef DECORATOR_H
#define DECORATOR_H

#include "behaviourtree.h"

class Decorator: public BehaviourTree
{
public:
    void addChild(Tree* child) override;
    BehaviourTree::ExecuteResult execute() override;
};

#endif // DECORATOR_H
