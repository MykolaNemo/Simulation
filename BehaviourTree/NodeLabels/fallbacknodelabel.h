#ifndef FALLBACKNODELABEL_H
#define FALLBACKNODELABEL_H

#include "nodelabel.h"

class FallbackNodeLabel: public NodeLabel
{
public:
    explicit FallbackNodeLabel(QWidget *parent=nullptr, Qt::WindowFlags f=Qt::WindowFlags());
    explicit FallbackNodeLabel(const QString &text, QWidget *parent=nullptr, Qt::WindowFlags f=Qt::WindowFlags());
    NodeType getNodeType() const override;

private:
    void init();
};

#endif // FALLBACKNODELABEL_H
