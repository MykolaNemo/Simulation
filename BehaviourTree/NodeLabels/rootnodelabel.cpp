#include "rootnodelabel.h"

RootNodeLabel::RootNodeLabel(QWidget *parent, Qt::WindowFlags f):
    NodeLabel (parent, f)
{
}

RootNodeLabel::RootNodeLabel(const QString &text, QWidget *parent, Qt::WindowFlags f):
    NodeLabel (text, parent, f)
{
}

NodeType RootNodeLabel::getNodeType() const
{
    return NodeType::Root;
}
