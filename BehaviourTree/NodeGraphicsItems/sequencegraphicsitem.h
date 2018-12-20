#ifndef SEQUENCEGRAPHICSITEM_H
#define SEQUENCEGRAPHICSITEM_H

#include "nodegraphicsitem.h"
#include <memory>

class SequenceGraphicsItem: public NodeGraphicsItem
{
public:
    explicit SequenceGraphicsItem(QGraphicsItem *parent = nullptr);
    std::shared_ptr<Tree> getTreeModel() const override;

protected:
    void init();

private:
    std::shared_ptr<Tree> mTreeModel;
};

#endif // SEQUENCEGRAPHICSITEM_H
