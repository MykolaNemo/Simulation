#ifndef LEAFGRAPHICSITEM_H
#define LEAFGRAPHICSITEM_H

#include "nodegraphicsitem.h"

class LeafGraphicsItem: public NodeGraphicsItem
{
public:
    explicit LeafGraphicsItem(QGraphicsItem *parent = nullptr);
    std::shared_ptr<Tree> getTreeModel() const override;

protected:
    void init();

private:
    std::shared_ptr<Tree> mTreeModel;
};

#endif // LEAFGRAPHICSITEM_H
