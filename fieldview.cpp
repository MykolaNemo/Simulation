#include "fieldview.h"

FieldView::FieldView(QGraphicsScene* scene, QWidget* parent):
    QGraphicsView(scene, parent)
{
    setStyleSheet("background:lightgreen;");
}

void FieldView::closeEvent(QCloseEvent *event)
{
    emit aboutToClose();
    QGraphicsView::closeEvent(event);
}
