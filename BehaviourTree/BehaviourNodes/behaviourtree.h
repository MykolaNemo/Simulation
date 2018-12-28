#ifndef BEHAVIOURTREE_H
#define BEHAVIOURTREE_H

#include <vector>
#include <string>
#include <chrono>

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
    int getValue() const;
    std::string getName() const;

    virtual void setValue(int value);
    virtual void addChild(BehaviourTree* child) = 0;
    virtual void removeChild(BehaviourTree* child) = 0;
    virtual std::vector<BehaviourTree*> getChildren() const = 0;
    virtual ExecuteResult execute(const std::chrono::milliseconds& tick) = 0;

protected:
    BehaviourTree(int value, std::string name, BehaviourTree* parent);
    BehaviourTree(const BehaviourTree&) = default;
    BehaviourTree(BehaviourTree&&) = default;
    BehaviourTree& operator=(const BehaviourTree&) = default;
    BehaviourTree& operator=(BehaviourTree&&) = default;

private:
    int mValue = 0;
    std::string mName;
    BehaviourTree* mParent;
};

#endif // BEHAVIOURTREE_H
