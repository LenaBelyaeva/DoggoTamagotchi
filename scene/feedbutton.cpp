#include "feedbutton.h"
#include <QtGui>
#include <QtWidgets>

feedButton::feedButton(Pet * ThePet, QWidget *parent) : QPushButton(parent)
{
    setIcon(QIcon("://img/Tacos.png"));
    setIconSize(QSize(32,32));

    int id = QFontDatabase::addApplicationFont("://fonts/ARCADECLASSIC.TTF");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont arcade(family, 11);

    tacoButton = new QPushButton("give taco");
    tacoButton->setFont(arcade);
    pieButton = new QPushButton("give pie");
    pieButton->setFont(arcade);
    juiceButton = new QPushButton("give juice");
    juiceButton->setFont(arcade);

    feedLayout = new QVBoxLayout;
    feedLayout -> setContentsMargins(0,20,0,0);
    feedLayout -> setSpacing(6);
    feedLayout -> addWidget(tacoButton);
    feedLayout -> addWidget(pieButton);
    feedLayout -> addWidget(juiceButton);

    connect(tacoButton, SIGNAL(clicked()), ThePet, SLOT(giveTaco()));
    connect(pieButton, SIGNAL(clicked()), ThePet, SLOT(givePie()));
    connect(juiceButton, SIGNAL(clicked()), ThePet, SLOT(giveJuice()));

    hideLayout();
}

void feedButton::hideLayout()
{
    tacoButton->hide();
    pieButton->hide();
    juiceButton->hide();
}

void feedButton::showLayout()
{
    tacoButton->show();
    pieButton->show();
    juiceButton->show();
}
