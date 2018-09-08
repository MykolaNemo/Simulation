#ifndef RANGETREE_H
#define RANGETREE_H

#include <memory>

struct TreeNode
{
    TreeNode(int _value):value(_value){}
    ~TreeNode() { delete left;delete right; }

    TreeNode* parent = nullptr;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
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
    TreeNode* minNode(TreeNode* node);
    void removeFromTheParentNode(TreeNode *node);

    TreeNode* mRoot = nullptr;
};

#endif // RANGETREE_H
