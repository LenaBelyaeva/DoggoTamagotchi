#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include <QtWidgets>
#include <scene/cleanbutton.h>
#include <scene/petbutton.h>
#include <scene/statsbutton.h>
#include <scene/nursebutton.h>
#include <scene/feedbutton.h>
#include <scene/pet.h>

#define left -1
#define right 1

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    Pet * ThePet;

    feedButton * fb;
    nurseButton * nb;
    statsButton * sb;
    cleanButton * cb;
    petButton * pb;

    QImage arr[6];
    int x;
    int moving;
    int maxX;
    int minX;
    int petState;
    void spriteUpdate();

    QVBoxLayout * mainLayout;
    QLabel * stats;

public slots:
    void showStats();

protected:
    void paintEvent(QPaintEvent *pe);
    void timerEvent(QTimerEvent *event);
};

#endif // WIDGET_H
