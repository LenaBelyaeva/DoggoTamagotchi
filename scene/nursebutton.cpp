#include <QtGui>
#include <QtWidgets>
#include <scene/pet.h>
#include "nursebutton.h"

nurseButton::nurseButton(Pet * ThePet, QWidget *parent) : QPushButton(parent)
{
    setIcon(QIcon("://img/FirstAidKit.png"));
    setIconSize(QSize(32,32));

    int id = QFontDatabase::addApplicationFont("://fonts/ARCADECLASSIC.TTF");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont arcade(family, 11);

    pillButton = new QPushButton("give pill");
    pillButton->setFont(arcade);
    injectionButton = new QPushButton("give injection");
    injectionButton->setFont(arcade);

    nurseLayout = new QVBoxLayout;
    nurseLayout -> setContentsMargins(0,20,0,0);
    nurseLayout -> setSpacing(6);
    nurseLayout -> addWidget(pillButton);
    nurseLayout -> addWidget(injectionButton);

    connect(pillButton, SIGNAL(clicked()), ThePet, SLOT(givePill()));
    connect(injectionButton, SIGNAL(clicked()), ThePet, SLOT(giveInjection()));

    hideLayout();
}

void nurseButton::hideLayout()
{
    pillButton->hide();
    injectionButton->hide();
}

void nurseButton::showLayout()
{
    pillButton->show();
    injectionButton->show();
}

