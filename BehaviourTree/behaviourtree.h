#ifndef BEHAVIOURTREE_H
#define BEHAVIOURTREE_H

#include "tree.h"

class BehaviourTree: public Tree
{
public:
    enum class ExecuteResult
    {
        SUCCESS = 0,
        FAILURE,
        RUNNING
    };
    BehaviourTree() = default;
    virtual ~BehaviourTree() = default;
    virtual ExecuteResult execute() = 0;
};

#endif // BEHAVIOURTREE_H
