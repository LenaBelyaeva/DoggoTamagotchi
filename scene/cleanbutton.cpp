#include "cleanbutton.h"
#include <QtGui>
#include <QtWidgets>
cleanButton::cleanButton(Pet * ThePet, QWidget *parent) : QPushButton(parent)
{
    setIcon(QIcon(":/img/icons/Dustpan.png"));
    setIconSize(QSize(32,32));
    cleanMenu = new QMenu;
    cleanMenu->setWindowFlags(cleanMenu->windowFlags() | Qt::NoDropShadowWindowHint);
    setMenu(cleanMenu);
    cleanMenu->addAction("clean", ThePet, SLOT(clean()));
}
