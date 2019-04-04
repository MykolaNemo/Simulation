#ifndef BEHAVIOURTREE_H
#define BEHAVIOURTREE_H

#include <vector>
#include <string>
#include <chrono>
#include <memory>

struct Blackboard;
class BehaviourTree
{
public:
    enum class ExecuteResult
    {
        SUCCESS = 0,
        FAILURE,
        RUNNING
    };
    virtual ~BehaviourTree(){}
    BehaviourTree* getParent() const;
    std::string getName() const;

    virtual BehaviourTree* addChild(BehaviourTree* child) = 0;
    virtual void removeChild(BehaviourTree* child) = 0;
    virtual std::vector<BehaviourTree*> getChildren() const = 0;
    virtual ExecuteResult execute(const std::chrono::milliseconds& tick,
                                  std::shared_ptr<Blackboard>& blackboard) = 0;

protected:
    BehaviourTree(std::string name, BehaviourTree* parent);
    BehaviourTree(const BehaviourTree&) = default;
    BehaviourTree(BehaviourTree&&) = default;
    BehaviourTree& operator=(const BehaviourTree&) = default;
    BehaviourTree& operator=(BehaviourTree&&) = default;

private:
    std::string mName;
    BehaviourTree* mParent;
};

#endif // BEHAVIOURTREE_H
