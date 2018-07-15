#include "petbutton.h"
#include <QtGui>
#include <QtWidgets>
#include <scene/pet.h>

petButton::petButton(Pet * ThePet, QWidget *parent) : QPushButton(parent)
{    
    setIcon(QIcon("://img/Body-Brush.png"));
    setIconSize(QSize(32,32));

    int id = QFontDatabase::addApplicationFont("://fonts/ARCADECLASSIC.TTF");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont arcade(family, 11);

    brushButton = new QPushButton("brush");
    brushButton->setFont(arcade);
    hugButton = new QPushButton("give hug");
    hugButton->setFont(arcade);
    ballButton = new QPushButton("give ball");
    ballButton->setFont(arcade);

    petLayout = new QVBoxLayout;
    petLayout -> setContentsMargins(0,20,0,0);
    petLayout -> setSpacing(6);
    petLayout -> addWidget(brushButton);
    petLayout -> addWidget(hugButton);
    petLayout -> addWidget(ballButton);

    connect(brushButton, SIGNAL(clicked()), ThePet, SLOT(giveBrush()));
    connect(hugButton, SIGNAL(clicked()), ThePet, SLOT(giveHug()));
    connect(ballButton, SIGNAL(clicked()), ThePet, SLOT(giveBall()));

    hideLayout();
}

void petButton::hideLayout()
{
    brushButton->hide();
    hugButton->hide();
    ballButton->hide();
}

void petButton::showLayout()
{
    brushButton->show();
    hugButton->show();
    ballButton->show();
}
