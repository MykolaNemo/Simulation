#ifndef SEQUENCENODELABEL_H
#define SEQUENCENODELABEL_H

#include "nodelabel.h"

class SequenceNodeLabel: public NodeLabel
{
public:
    explicit SequenceNodeLabel(QWidget *parent=nullptr, Qt::WindowFlags f=Qt::WindowFlags());
    explicit SequenceNodeLabel(const QString &text, QWidget *parent=nullptr, Qt::WindowFlags f=Qt::WindowFlags());
    NodeType getNodeType() const override;

private:
    void init();
};

#endif // SEQUENCENODELABEL_H
