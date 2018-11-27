#include "tree.h"

void Tree::setValue(int _value)
{
    value = _value;
}

int Tree::getValue() const
{
    return value;
}

void Tree::addChild(Tree* child)
{
    if(child)
    {
        child->parent = this;
        children.push_back(child);
    }
}

void Tree::removeChild(Tree* child)
{
    if(child)
    {
        children.erase(std::remove(children.begin(), children.end(), child), children.end());
    }
}

std::vector<Tree*> Tree::getChildren() const
{
    return children;
}
