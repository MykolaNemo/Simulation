#ifndef LEAFNODELABEL_H
#define LEAFNODELABEL_H

#include "nodelabel.h"

class LeafNodeLabel: public NodeLabel
{
public:
    explicit LeafNodeLabel(QWidget *parent=nullptr, Qt::WindowFlags f=Qt::WindowFlags());
    explicit LeafNodeLabel(const QString &text, QWidget *parent=nullptr, Qt::WindowFlags f=Qt::WindowFlags());
    NodeType getNodeType() const override;

private:
    void init();
};

#endif // LEAFNODELABEL_H

