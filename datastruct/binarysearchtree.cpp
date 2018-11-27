#include "binarysearchtree.h"

BinarySearchTree::~BinarySearchTree()
{
    delete mRoot;
}

void BinarySearchTree::addValue(int value)
{
    if(!mRoot)
    {
        mRoot = new Tree(value);
        return;
    }

    Tree* currentNode = mRoot;
    while(true)
    {
        if(value > currentNode->value)
        {
            if(currentNode->right)
            {
                currentNode = currentNode->right;
                continue;
            }
            auto newNode = new Tree(value);
            newNode->parent = currentNode;
            currentNode->right = newNode;
            break;
        }
        else if(currentNode->left)
        {
            currentNode = currentNode->left;
            continue;
        }

        auto newNode = new Tree(value);
        newNode->parent = currentNode;
        currentNode->left = newNode;
        break;
    }
}

void BinarySearchTree::removeValue(int value)
{
    if(!mRoot) return;

    Tree* currentNode = mRoot;
    while(currentNode)
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
                    Tree* min = minNode(currentNode);
                    currentNode->value = min->value;

                    removeFromTheParentNode(min);
                }
            }
            else if(currentNode->left)//only left child present
            {
                currentNode->value = currentNode->left->value;
                delete currentNode->left;
                currentNode->left = nullptr;
            }
            else if(currentNode->right)//only right child present
            {
                currentNode->value = currentNode->right->value;
                delete currentNode->right;
                currentNode->right = nullptr;
            }
            else // no children present
            {
                removeFromTheParentNode(currentNode);
            }
        }
    }
}

void BinarySearchTree::removeFromTheParentNode(Tree* node)
{
    if(!node || !node->parent) return;

    Tree* parent = node->parent;
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

Tree* BinarySearchTree::minNode(Tree* node)
{
    if(!node) return nullptr;

    Tree* currentNode = node;
    while(currentNode->left)
    {
        currentNode = node->left;
    }
    return currentNode;
}
