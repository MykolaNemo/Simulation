#include "fallbacknodelabel.h"

FallbackNodeLabel::FallbackNodeLabel::FallbackNodeLabel(QWidget *parent, Qt::WindowFlags f):
    FallbackNodeLabel ("", parent, f){}

FallbackNodeLabel::FallbackNodeLabel::FallbackNodeLabel(const QString &text, QWidget *parent, Qt::WindowFlags f):
    NodeLabel (text, parent, f)
{
    init();
}

NodeType FallbackNodeLabel::getNodeType() const
{
    return NodeType::Fallback;
}

void FallbackNodeLabel::init()
{

}
