#include "nodelabel.h"

#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>
#include <QPainter>

NodeLabel::NodeLabel(QWidget *parent, Qt::WindowFlags f):
    QLabel(parent, f)
{
}

NodeLabel::NodeLabel(const QString &text, QWidget *parent, Qt::WindowFlags f):
    QLabel(text, parent, f)
{

}

void NodeLabel::mousePressEvent(QMouseEvent *event)
{
    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << static_cast<int>(this->getNodeType());

    auto mimeData = new QMimeData;
    mimeData->setData("application/x-dndNode", itemData);

    auto drag = new QDrag(this);
    drag->setMimeData(mimeData);
    if(this->pixmap())
    {
        drag->setPixmap(*this->pixmap());
    }
    drag->setHotSpot(event->pos());
    drag->exec(Qt::CopyAction);
}

void NodeLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
    QPainter p;
    p.begin(this);

    QPen pen;
    pen.setColor(QColor(0xaa,0xaa,0xaa));
    pen.setWidth(2);
    p.setPen(pen);
    p.drawRect(1,1,width()-2, height()-2);
    p.end();
}
