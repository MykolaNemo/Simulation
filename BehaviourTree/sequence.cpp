#include "sequence.h"

BehaviourTree::ExecuteResult Sequence::execute()
{
    for(Tree* child : children)
    {
        ExecuteResult result = static_cast<BehaviourTree*>(child)->execute();
        switch (result) {
        case ExecuteResult::FAILURE:
            return ExecuteResult::FAILURE;
        case ExecuteResult::RUNNING:
            return ExecuteResult::RUNNING;
        case ExecuteResult::SUCCESS:
            break;
        }
    }
    return ExecuteResult::SUCCESS;
}
