#include "cleanbutton.h"
#include <QtGui>
#include <QtWidgets>
cleanButton::cleanButton(Pet * ThePet, QWidget *parent) : QPushButton(parent)
{
    setIcon(QIcon("://img/Dustpan.png"));
    setIconSize(QSize(32,32));
    connect(this, SIGNAL(clicked()), ThePet, SLOT(clean()));
}
