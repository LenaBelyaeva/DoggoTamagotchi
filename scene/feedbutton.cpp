#include "feedbutton.h"
#include <QtGui>
#include <QtWidgets>

feedButton::feedButton(Pet * ThePet, QWidget *parent) : QPushButton(parent)
{
    setIcon(QIcon("://img/Tacos.png"));
    setIconSize(QSize(32,32));
    feedMenu = new QMenu;
    setMenu(feedMenu);
    feedMenu->setWindowFlags(feedMenu->windowFlags() | Qt::NoDropShadowWindowHint);
    feedMenu->addAction("give taco", ThePet, SLOT(giveTaco()));
    feedMenu->addAction("give pie", ThePet, SLOT(givePie()));
    feedMenu->addAction("give juice", ThePet, SLOT(giveJuice()));
}
