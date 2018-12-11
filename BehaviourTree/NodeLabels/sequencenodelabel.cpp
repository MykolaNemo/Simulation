#include "sequencenodelabel.h"

SequenceNodeLabel::SequenceNodeLabel(QWidget *parent, Qt::WindowFlags f):
    NodeLabel (parent, f)
{
    init();
}

SequenceNodeLabel::SequenceNodeLabel(const QString &text, QWidget *parent, Qt::WindowFlags f):
    NodeLabel (text, parent, f)
{
    init();
}

NodeType SequenceNodeLabel::getNodeType() const
{
    return NodeType::Sequence;
}

void SequenceNodeLabel::init()
{

}
