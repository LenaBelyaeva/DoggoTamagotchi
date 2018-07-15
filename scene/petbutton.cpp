#include "petbutton.h"
#include <QtGui>
#include <QtWidgets>
#include <scene/pet.h>

petButton::petButton(Pet * ThePet, QWidget *parent) : QPushButton(parent)
{    
    setIcon(QIcon("://img/Body-Brush.png"));
    setIconSize(QSize(32,32));
    petMenu = new QMenu;
    petMenu->setWindowFlags(petMenu->windowFlags() | Qt::NoDropShadowWindowHint);
    setMenu(petMenu);
    petMenu->addAction("brush", ThePet, SLOT(giveBrush()));
    petMenu->addAction("give hug", ThePet, SLOT(giveHug()));
    petMenu->addAction("give ball", ThePet, SLOT(giveBall()));
}
