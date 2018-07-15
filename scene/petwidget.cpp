#include "petwidget.h"
#include <QtGui>
#include <QtWidgets>

petWidget::petWidget(QWidget *parent) : QWidget(parent)
{
    //setFixedSize(49,32);
}

void petWidget::paintEvent(QPaintEvent *pe)
{
    QPainter p(this);
    p.drawImage(QPoint(140,300), QImage("://img/walk-left-1.png"));
}
