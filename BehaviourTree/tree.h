#pragma once

#include <memory>
#include <vector>
#include <algorithm>

class Tree: public std::enable_shared_from_this<Tree>
{
public:
    enum class NodeType
    {
        TickGenerator,
        Sequence,
        Fallback,
        Leaf
    };

    Tree(NodeType _type):type(_type){}

    void addChild(const std::shared_ptr<Tree> &childTree)
    {
        if(!childTree) return;

        if(std::find(children.begin(), children.end(), childTree) == children.end())
        {
            childTree->parent = shared_from_this();
            children.push_back(childTree);
        }
    }

    void removeChild(const std::shared_ptr<Tree> &childTree)
    {
        if(!childTree) return;

        auto deleteIt = std::remove(children.begin(), children.end(), childTree);
        if(deleteIt != children.end())
        {
            childTree->parent = std::shared_ptr<Tree>();
            children.erase(deleteIt);
        }
    }

    std::vector<std::shared_ptr<Tree>> getChildren() const
    {
        return children;
    }

    NodeType getType() const
    {
        return type;
    }

private:
    std::shared_ptr<Tree> parent;
    std::vector<std::shared_ptr<Tree>> children;
    NodeType type = NodeType::Leaf;
};
