#ifndef ROOTGRAPHICSITEM_H
#define ROOTGRAPHICSITEM_H

#include "nodegraphicsitem.h"
#include <memory>

class RootGraphicsItem: public NodeGraphicsItem
{
public:
    explicit RootGraphicsItem(QGraphicsItem *parent = nullptr);
    std::shared_ptr<Tree> getTreeModel() const override;

private:
    void init();    
    std::shared_ptr<Tree> mTreeModel;
};

#endif // ROOTGRAPHICSITEM_H
