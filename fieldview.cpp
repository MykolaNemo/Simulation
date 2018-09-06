#include "fieldview.h"

FieldView::FieldView(QGraphicsScene* scene, QWidget* parent):
    QGraphicsView(scene, parent)
{

}

void FieldView::closeEvent(QCloseEvent *event)
{
    emit aboutToClose();
    QGraphicsView::closeEvent(event);
}
