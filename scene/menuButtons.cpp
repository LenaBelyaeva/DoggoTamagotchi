#include "menuButtons.h"
#include <QtGui>
#include <QtWidgets>
#include <scene/mainScene.h>

feedButton::feedButton(QWidget *parent) : menuButton(parent)
{
    setIcon(QIcon("://img/Tacos.png"));

    tacoButton = new QPushButton("give taco");
    tacoButton->setFont(QFont(MainScene::mainFontFamily, 11));
    pieButton = new QPushButton("give pie");
    pieButton->setFont(QFont(MainScene::mainFontFamily, 11));
    juiceButton = new QPushButton("give juice");
    juiceButton->setFont(QFont(MainScene::mainFontFamily, 11));

    menuLayout = new QVBoxLayout;
    menuLayout -> setContentsMargins(0,20,0,0);
    menuLayout -> setSpacing(6);
    menuLayout -> addWidget(tacoButton);
    menuLayout -> addWidget(pieButton);
    menuLayout -> addWidget(juiceButton);

    connect(tacoButton, SIGNAL(clicked()), &ThePet, SLOT(giveTaco()));
    connect(pieButton, SIGNAL(clicked()), &ThePet, SLOT(givePie()));
    connect(juiceButton, SIGNAL(clicked()), &ThePet, SLOT(giveJuice()));

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


nurseButton::nurseButton(QWidget *parent) : menuButton(parent)
{
    setIcon(QIcon("://img/FirstAidKit.png"));

    pillButton = new QPushButton("give pill");
    pillButton->setFont(QFont(MainScene::mainFontFamily, 11));
    injectionButton = new QPushButton("give injection");
    injectionButton->setFont(QFont(MainScene::mainFontFamily, 11));

    menuLayout = new QVBoxLayout;
    menuLayout -> setContentsMargins(0,20,0,0);
    menuLayout -> setSpacing(6);
    menuLayout -> addWidget(pillButton);
    menuLayout -> addWidget(injectionButton);

    connect(pillButton, SIGNAL(clicked()), &ThePet, SLOT(givePill()));
    connect(injectionButton, SIGNAL(clicked()), &ThePet, SLOT(giveInjection()));

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


petButton::petButton(QWidget *parent) : menuButton(parent)
{
    setIcon(QIcon("://img/Body-Brush.png"));

    brushButton = new QPushButton("brush");
    brushButton->setFont(QFont(MainScene::mainFontFamily, 11));
    hugButton = new QPushButton("give hug");
    hugButton->setFont(QFont(MainScene::mainFontFamily, 11));
    ballButton = new QPushButton("give ball");
    ballButton->setFont(QFont(MainScene::mainFontFamily, 11));

    menuLayout = new QVBoxLayout;
    menuLayout -> setContentsMargins(0,20,0,0);
    menuLayout -> setSpacing(6);
    menuLayout -> addWidget(brushButton);
    menuLayout -> addWidget(hugButton);
    menuLayout -> addWidget(ballButton);

    connect(brushButton, SIGNAL(clicked()), &ThePet, SLOT(giveBrush()));
    connect(hugButton, SIGNAL(clicked()), &ThePet, SLOT(giveHug()));
    connect(ballButton, SIGNAL(clicked()), &ThePet, SLOT(giveBall()));

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

statsButton::statsButton(QWidget *parent) : menuButton(parent)
{
    setIcon(QIcon("://img/Clipboard.png"));

    stats = new QLabel;
    stats->setFont(QFont(MainScene::mainFontFamily,  12));
    stats->setAlignment(Qt::AlignCenter);

    menuLayout = new QVBoxLayout;
    menuLayout -> setContentsMargins(0,10,0,0);
    menuLayout -> addWidget(stats);
}

void statsButton::hideLayout()
{
    stats->hide();
}

void statsButton::showLayout()
{
    QString str("Age: ");
    str.append(QString::number(ThePet.getAge()));
    str.append("\n");
    str.append("Hungry: ");
    str.append(QString::number(ThePet.getHungry()));
    str.append("\n");
    str.append("Health: ");
    str.append(QString::number(ThePet.getHealth()));
    str.append("\n");
    str.append("Happiness: ");
    str.append(QString::number(ThePet.getHappiness()));
    str.append("\n");
    str.append("Poops: ");
    str.append(QString::number(ThePet.getPoops()));
    stats->setText(str);
    stats->show();
}

cleanButton::cleanButton(QWidget *parent) : menuButton(parent)
{
    setIcon(QIcon("://img/Dustpan.png"));
    connect(this, SIGNAL(clicked()), &ThePet, SLOT(clean()));
}
