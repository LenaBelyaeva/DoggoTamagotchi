#include <QtGui>
#include <QtWidgets>
#include <scene/pet.h>
#include "nursebutton.h"

nurseButton::nurseButton(Pet * ThePet, QWidget *parent) : QPushButton(parent)
{
    setIcon(QIcon("://img/FirstAidKit.png"));
    setIconSize(QSize(32,32));
    nurseMenu = new QMenu;
    setMenu(nurseMenu);
    nurseMenu->setWindowFlags(nurseMenu->windowFlags() | Qt::NoDropShadowWindowHint);
    nurseMenu->addAction("give pill", ThePet, SLOT(givePill()));
    nurseMenu->addAction("give injection", ThePet, SLOT(giveInjection()));

}
