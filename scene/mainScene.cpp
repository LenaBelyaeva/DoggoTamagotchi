#include <QtGui>
#include <QtWidgets>
#include "mainScene.h"
#include "pet.h"
#include "menuButtons.h"


QString MainScene::mainFontFamily;

MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    int id = QFontDatabase::addApplicationFont("://fonts/ARCADECLASSIC.TTF");
    mainFontFamily = QFontDatabase::applicationFontFamilies(id).at(0);

    setFixedSize(QSize(278,367));

    mainLayout = new QVBoxLayout(this);

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
    mainLayout->addLayout(buttonLayout);
    mainLayout->addStretch();

    petSprites[0] = QImage("://img/walk-left-1.png");
    petSprites[1] = QImage("://img/walk-left-2.png");
    petSprites[2] = QImage("://img/walk-left-3.png");
    petSprites[3] = QImage("://img/walk-right-1.png");
    petSprites[4] = QImage("://img/walk-right-2.png");
    petSprites[5] = QImage("://img/walk-right-3.png");

    maxX = size().width();
    minX = -petSprites[0].width();
    x = (maxX+minX)/2;
    movingDirection = left;
    petState = 0;

    startTimer(MILISEC_PER_FRAME);
    startTimer(MILISEC_PER_UPDATE);
}

void MainScene::showMenu() {
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

void MainScene::showButtonLayout(menuButton * mb) {
    mainLayout -> insertLayout(mainLayout->count()-1, mb->menuLayout);
    mb -> showLayout();
}

void MainScene::hideButtonLayout(menuButton * mb) {
    mb->hideLayout();
    mainLayout->removeItem(mb->menuLayout);
}

void MainScene::paintEvent(QPaintEvent * pe)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    p.drawImage(QPoint(x,300), petSprites[petState]);
}

void MainScene::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == 1)
        this->spriteUpdate();
    if(event->timerId() == 2)
        ThePet.Update();
}

void MainScene::spriteUpdate()
{
    if (movingDirection == left){
        if (--x < minX){
            x = minX;
            movingDirection = right;
            petState = 3;
        }
        else if (++petState > 2)
                petState = 0;
    }
    else {
        if (++x > maxX){
            x = maxX;
            movingDirection = left;
            petState = 0;
        }
        else if (++petState > 5)
                petState = 3;
    }
    update();
}
