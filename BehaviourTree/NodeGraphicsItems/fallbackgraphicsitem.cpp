#include "fallbackgraphicsitem.h"

#include <QPainter>
#include <QTextDocument>
#include "tree.h"

FallbackGraphicsItem::FallbackGraphicsItem(QGraphicsItem *parent):
    NodeGraphicsItem (0,0,130,55,parent)
{
    init();
}

std::shared_ptr<Tree> FallbackGraphicsItem::getTreeModel() const
{
    return mTreeModel;
}

void FallbackGraphicsItem::init()
{
    mTreeModel = std::make_shared<Tree>(Tree::NodeType::Fallback);

    QPen pen;
    pen.setWidth(2);
    pen.setColor(QColor(0xcc,0xcc,0x55));
    setPen(pen);

    auto textItem = new QGraphicsTextItem("Fallback", this);
    textItem->setTextInteractionFlags(Qt::TextEditorInteraction);
    connect(textItem->document(), &QTextDocument::contentsChange, [this, textItem](int, int, int){
        textItem->adjustSize();
        const auto size = this->boundingRect().size();
        const auto textItemSize = textItem->boundingRect().size();
        textItem->setPos((size.width() - textItemSize.width())/2.0,
                         (size.height() - textItemSize.height())/2.0);
        this->mTreeModel->setName(textItem->toPlainText().toStdString());
    });
    const auto size = boundingRect().size();
    const auto textItemSize = textItem->boundingRect().size();
    textItem->setPos((size.width() - textItemSize.width())/2.0,
                     (size.height() - textItemSize.height())/2.0);
}
