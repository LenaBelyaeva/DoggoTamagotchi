#include "scene/pet.h"
#include <QApplication>
#include <QtGui>
#include <QtWidgets>
#include <scene/mainScene.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainScene w;
    w.setObjectName("main");
    qApp->setStyleSheet("#main{background-image: url(://img/background.png)} "
                        "QPushButton { border: none; color: white } "
                        "QPushButton:hover:pressed { border: none; color: white; font-size: 14px; }  "
                        "QPushButton:hover { border: none; color: white; font-size: 17px; } "
                        "QLabel { color : white; }");

    w.show();
    return a.exec();
}
