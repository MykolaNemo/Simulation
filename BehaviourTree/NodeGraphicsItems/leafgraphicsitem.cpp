#include "leafgraphicsitem.h"

#include <QPainter>
#include <QTextDocument>
#include "tree.h"

LeafGraphicsItem::LeafGraphicsItem(QGraphicsItem *parent):
    NodeGraphicsItem (0,0,130,55,parent)
{
    init();
    hideAnchorItem();
}

std::shared_ptr<Tree> LeafGraphicsItem::getTreeModel() const
{
    return mTreeModel;
}

void LeafGraphicsItem::init()
{
    mTreeModel = std::make_shared<Tree>(Tree::NodeType::Leaf);

    QPen pen;
    pen.setWidth(2);
    pen.setColor(QColor(0x55,0xff,0x99));
    setPen(pen);

    auto textItem = new QGraphicsTextItem("Leaf", this);
    textItem->setTextInteractionFlags(Qt::TextEditorInteraction);
    connect(textItem->document(), &QTextDocument::contentsChange, [this, textItem](int, int, int){
        textItem->adjustSize();
        const auto size = this->boundingRect().size();
        const auto textItemSize = textItem->boundingRect().size();
        textItem->setPos((size.width() - textItemSize.width())/2.0,
                         (size.height() - textItemSize.height())/2.0);
    });
    const auto size = boundingRect().size();
    const auto textItemSize = textItem->boundingRect().size();
    textItem->setPos((size.width() - textItemSize.width())/2.0,
                     (size.height() - textItemSize.height())/2.0);
}
