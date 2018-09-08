#include "binarysearchtree.h"

BinarySearchTree::~BinarySearchTree()
{
    delete mRoot;
}

void BinarySearchTree::addValue(int value)
{
    if(!mRoot)
    {
        mRoot = new TreeNode(value);
        return;
    }

    TreeNode* currentNode = mRoot;
    while(true)
    {
        if(value > currentNode->value)
        {
            if(currentNode->right)
            {
                currentNode = currentNode->right;
                continue;
            }
            TreeNode* newNode = new TreeNode(value);
            newNode->parent = currentNode;
            currentNode->right = newNode;
            break;
        }
        else if(currentNode->left)
        {
            currentNode = currentNode->left;
            continue;
        }
        TreeNode* newNode = new TreeNode(value);
        newNode->parent = currentNode;
        currentNode->left = newNode;
        break;
    }
}

void BinarySearchTree::removeValue(int value)
{
    if(!mRoot) return;

    TreeNode* currentNode = mRoot;
    while(true)
    {
        if(value > currentNode->value)//bigger->go right
        {
            if(currentNode->right)
            {
                currentNode = currentNode->right;
                continue;
            }
            break;
        }
        else if(value < currentNode->value)//smaller->go left
        {
            if(currentNode->left)
            {
                currentNode = currentNode->right;
                continue;
            }
            break;
        }
        else //found it
        {
            if(currentNode->left && currentNode->right)//both children present
            {
                if(!currentNode->right->left)
                {
                    currentNode->value = currentNode->right->value;
                    currentNode->right = currentNode->right->right;
                }
                else
                {
                    TreeNode* min = minNode(currentNode);
                    currentNode->value = min->value;

                    removeFromTheParentNode(min);
                }
            }
            else if(currentNode->left)//only left child present
            {
                currentNode->value = currentNode->left->value;
                delete currentNode->left;
            }
            else if(currentNode->right)//only right child present
            {
                currentNode->value = currentNode->right->value;
                delete currentNode->right;
            }
            else // no children present
            {
                removeFromTheParentNode(currentNode);
            }
        }
    }
}

void BinarySearchTree::removeFromTheParentNode(TreeNode* node)
{
    if(!node || !node->parent) return;

    TreeNode* parent = node->parent;
    if(parent->left == node)
    {
        delete parent->left;
        parent->left = nullptr;
    }
    else if(parent->right == node)
    {
        delete parent->right;
        parent->right = nullptr;
    }
}

TreeNode* BinarySearchTree::minNode(TreeNode* node)
{
    if(!node) return nullptr;

    TreeNode* currentNode = node;
    while(currentNode->left)
    {
        currentNode = node->left;
    }
    return currentNode;
}
