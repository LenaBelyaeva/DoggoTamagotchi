#include "scene/pet.h"
#include <QApplication>
#include <QtGui>
#include <QtWidgets>
#include <scene/widget.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setObjectName("main");
    qApp->setStyleSheet("#main{background-image: url(://img/background.png)} QPushButton { border: none } QMenu { border: none; background-color: #CD96CD;} QLabel { color : white; }");

    w.show();
    return a.exec();
}
