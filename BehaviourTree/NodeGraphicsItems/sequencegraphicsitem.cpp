#include "sequencegraphicsitem.h"

#include <QPainter>
#include "tree.h"

SequenceGraphicsItem::SequenceGraphicsItem(QGraphicsItem *parent):
    NodeGraphicsItem (0,0,130,55,parent)
{
    init();
}

std::shared_ptr<Tree> SequenceGraphicsItem::getTreeModel() const
{
    return mTreeModel;
}

void SequenceGraphicsItem::init()
{
    mTreeModel = std::make_shared<Tree>(Tree::NodeType::Sequence);

    QPen pen;
    pen.setWidth(2);
    pen.setColor(QColor(0x99,0xcc,0xcc));
    setPen(pen);

    QGraphicsSimpleTextItem *textItem = new QGraphicsSimpleTextItem("Sequence", this);
    const auto size = boundingRect().size();
    const auto textItemSize = textItem->boundingRect().size();
    textItem->setPos((size.width() - textItemSize.width())/2.0,
                     (size.height() - textItemSize.height())/2.0);
}
