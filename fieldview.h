#ifndef FIELDVIEW_H
#define FIELDVIEW_H

#include <QGraphicsView>

class FieldView: public QGraphicsView
{
    Q_OBJECT
public:
    explicit FieldView(QGraphicsScene *scene, QWidget *parent = nullptr);

signals:
    void aboutToClose();

protected:
    void closeEvent(QCloseEvent* event);
};

#endif // FIELDVIEW_H
