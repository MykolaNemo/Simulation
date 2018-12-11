#ifndef NODELABEL_H
#define NODELABEL_H

#include <QLabel>

enum class NodeType
{
    Sequence = 0,
    Fallback
};

class NodeLabel: public QLabel
{
public:
    explicit NodeLabel(QWidget *parent=nullptr, Qt::WindowFlags f=Qt::WindowFlags());
    explicit NodeLabel(const QString &text, QWidget *parent=nullptr, Qt::WindowFlags f=Qt::WindowFlags());
    virtual NodeType getNodeType() const = 0;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent* event) override;
};

#endif // NODELABEL_H
