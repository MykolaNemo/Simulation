#ifndef RANGETREE_H
#define RANGETREE_H

#include <memory>

struct Tree
{
    Tree(int _value):value(_value){}
    ~Tree() { delete left;delete right; }

    Tree* parent = nullptr;
    Tree* left = nullptr;
    Tree* right = nullptr;
    int value = 0;
};

class BinarySearchTree
{
public:
    BinarySearchTree() = default;
    ~BinarySearchTree();
    void addValue(int value);
    void removeValue(int value);

private:
    Tree* minNode(Tree* node);
    void removeFromTheParentNode(Tree *node);

    Tree* mRoot = nullptr;
};

#endif // RANGETREE_H
