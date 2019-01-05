#include "leafnodelabel.h"

LeafNodeLabel::LeafNodeLabel(QWidget *parent, Qt::WindowFlags f):
    LeafNodeLabel("", parent, f){}

LeafNodeLabel::LeafNodeLabel(const QString &text, QWidget *parent, Qt::WindowFlags f):
    NodeLabel (text, parent, f)
{
    init();
}

NodeType LeafNodeLabel::getNodeType() const
{
    return NodeType::Leaf;
}

void LeafNodeLabel::init()
{

}
