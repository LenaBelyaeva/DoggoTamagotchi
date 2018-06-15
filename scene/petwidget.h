#ifndef PETWIDGET_H
#define PETWIDGET_H

#include <QWidget>

class petWidget : public QWidget
{
    Q_OBJECT
public:
    explicit petWidget(QWidget *parent = nullptr);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *pe);
};

#endif // PETWIDGET_H
