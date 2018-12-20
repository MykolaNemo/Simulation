#ifndef FALLBACKGRAPHICSITEM_H
#define FALLBACKGRAPHICSITEM_H

#include "nodegraphicsitem.h"

class FallbackGraphicsItem: public NodeGraphicsItem
{
public:
    explicit FallbackGraphicsItem(QGraphicsItem *parent = nullptr);
    std::shared_ptr<Tree> getTreeModel() const override;

protected:
    void init();

private:
    std::shared_ptr<Tree> mTreeModel;
};

#endif // FALLBACKGRAPHICSITEM_H
