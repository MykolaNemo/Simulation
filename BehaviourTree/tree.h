#ifndef TREE_H
#define TREE_H

#include <vector>
#include <algorithm>

class Tree
{
protected:
    explicit Tree(int _value = 0, Tree* _parent = nullptr)
        : parent(_parent)
        , value(_value)
    {
        if(parent != nullptr)
        {
            parent->children.push_back(this);
        }
    }
    virtual ~Tree() = default;
    Tree(const Tree&) = default;
    Tree(Tree&&) = default;
    Tree& operator=(const Tree&) = default;
    Tree& operator=(Tree&&) = default;

    virtual void setValue(int _value);
    virtual int getValue() const;
    virtual void addChild(Tree* child);
    virtual void removeChild(Tree* child);
    virtual std::vector<Tree*> getChildren() const;

    Tree* parent = nullptr;
    std::vector<Tree*> children;
    int value = 0;
};
#endif // TREE_H
