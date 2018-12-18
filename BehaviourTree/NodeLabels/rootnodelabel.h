#ifndef ROOTNODELABEL_H
#define ROOTNODELABEL_H

#include "nodelabel.h"

class RootNodeLabel: public NodeLabel
{
public:
    explicit RootNodeLabel(QWidget *parent = nullptr, Qt::WindowFlags f=Qt::WindowFlags());
    explicit RootNodeLabel(const QString &text, QWidget *parent = nullptr, Qt::WindowFlags f=Qt::WindowFlags());
    NodeType getNodeType() const override;
};

#endif // ROOTNODELABEL_H
