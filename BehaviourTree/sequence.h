#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "behaviourtree.h"

class Sequence: public BehaviourTree
{
public:
    Sequence() = default;
    BehaviourTree::ExecuteResult execute() override;
};

#endif // SEQUENCE_H
