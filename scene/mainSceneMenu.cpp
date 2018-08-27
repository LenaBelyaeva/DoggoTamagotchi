#include "mainSceneMenu.h"
#include "scene/menubuttons.h"
#include <QtGui>
#include <QtWidgets>
#include <scene/pet.h>

MainSceneMenu::MainSceneMenu(QWidget *parent) : QVBoxLayout(parent)
{
    menuButtons[0] = new statsButton();
    menuButtons[1] = new feedButton();
    menuButtons[2] = new petButton();
    menuButtons[3] = new nurseButton();
    menuButtons[4] = new cleanButton();

    QHBoxLayout * buttonLayout = new QHBoxLayout;
    buttonLayout->setAlignment(Qt::AlignTop);
    for(unsigned int i = 0; i < 4; i++){
        connect(menuButtons[i], SIGNAL(clicked()), this, SLOT(showMenu()));
        buttonLayout->addWidget(menuButtons[i]);
    }
    buttonLayout->addWidget(menuButtons[4]);

    this->addLayout(buttonLayout);
    this->addStretch();
}


void MainSceneMenu::showMenu() {
    QObject * button = QObject::sender();
    Menu senderButton = none;
    for (unsigned i = 0; i < 4; i++){
        if (menuButtons[i] == button)
            senderButton = Menu(i);
    }
    if (senderButton == none)
        return;

    if (currentMenu != none)
        hideButtonLayout(menuButtons[currentMenu]);

    if (currentMenu == senderButton){
        currentMenu = none;
    }
    else {
        showButtonLayout(menuButtons[senderButton]);
        currentMenu = senderButton;
    }
}

void MainSceneMenu::showButtonLayout(menuButton * mb) {
    this -> insertLayout(this->count()-1, mb->menuLayout);
    mb -> showLayout();
}

void MainSceneMenu::hideButtonLayout(menuButton * mb) {
    mb->hideLayout();
    this->removeItem(mb->menuLayout);
}
