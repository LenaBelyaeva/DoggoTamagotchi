#include "widget.h"
#include <QtGui>
#include <QtWidgets>
#include "cleanbutton.h"
#include "petbutton.h"
#include "statsbutton.h"
#include "nursebutton.h"
#include "feedbutton.h"
#include "pet.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    ThePet = new Pet;

    setFixedSize(QSize(278,367));

    mainLayout = new QVBoxLayout(this);

    fb = new feedButton(ThePet);
    nb = new nurseButton(ThePet);
    sb = new statsButton(ThePet);
    pb = new petButton(ThePet);
    cb = new cleanButton(ThePet);
    connect(sb, SIGNAL(clicked()), this, SLOT(showStats()));
    connect(fb, SIGNAL(clicked()), this, SLOT(showFeedMenu()));
    connect(pb, SIGNAL(clicked()), this, SLOT(showPetMenu()));
    connect(nb, SIGNAL(clicked()), this, SLOT(showNurseMenu()));

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->setAlignment(Qt::AlignTop);
    buttonLayout->addWidget(sb);
    buttonLayout->addWidget(fb);
    buttonLayout->addWidget(cb);
    buttonLayout->addWidget(pb);
    buttonLayout->addWidget(nb);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addStretch();

    int id = QFontDatabase::addApplicationFont("://fonts/ARCADECLASSIC.TTF");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont arcade(family, 12);

    stats = new QLabel;
    stats->setFont(arcade);
    stats->setAlignment(Qt::AlignCenter);

    QImage wl1("://img/walk-left-1.png");
    QImage wl2("://img/walk-left-2.png");
    QImage wl3("://img/walk-left-3.png");
    QImage wr1("://img/walk-right-1.png");
    QImage wr2("://img/walk-right-2.png");
    QImage wr3("://img/walk-right-3.png");
    arr[0] = wl1;
    arr[1] = wl2;
    arr[2] = wl3;
    arr[3] = wr1;
    arr[4] = wr2;
    arr[5] = wr3;
    maxX = size().width();
    minX = -wl1.width();
    x = (maxX+minX)/2;
    moving = left;
    petState = 0;

    startTimer(200);
    startTimer(60000);
}

void Widget::showStats()
{  
    bool show = isShowing[stat];
    for (int i = 0; i < 4; i++){
        hideMenu(i);
        isShowing[i] = false;
    }
    if (show)
    {
        isShowing[stat] = false;
        stats ->hide();
        mainLayout -> removeWidget(stats);
    }
    else
    {
        isShowing[stat] = true;
        QString str("Age: ");
        str.append(QString::number(ThePet->getAge()));
        str.append("\n");
        str.append("Hungry: ");
        str.append(QString::number(ThePet->getHungry()));
        str.append("\n");
        str.append("Health: ");
        str.append(QString::number(ThePet->getHealth()));
        str.append("\n");
        str.append("Happiness: ");
        str.append(QString::number(ThePet->getHappiness()));
        str.append("\n");
        str.append("Poops: ");
        str.append(QString::number(ThePet->getPoops()));
        stats->setText(str);
        mainLayout -> insertWidget(mainLayout->count()-1, stats);
        stats->show();
        return;
    }
}

void Widget::showFeedMenu()
{
    bool show = isShowing[feed];
    for (int i = 0; i < 4; i++){
        hideMenu(i);
        isShowing[i] = false;
    }
    if (!show)
    {
        isShowing[feed] = true;
        mainLayout -> insertLayout(mainLayout->count()-1, fb->feedLayout);
        fb->showLayout();
    }
    else
    {
        isShowing[feed] = false;
        fb->hideLayout();
        mainLayout -> removeItem(fb->feedLayout);
    }
}

void Widget::showPetMenu()
{
    bool show = isShowing[pet];
    for (int i = 0; i < 4; i++){
        hideMenu(i);
        isShowing[i] = false;
    }
    if (!show)
    {
        isShowing[pet] = true;
        mainLayout -> insertLayout(mainLayout->count()-1, pb->petLayout);
        pb->showLayout();
    }
    else
    {
        isShowing[pet] = false;
        pb->hideLayout();
        mainLayout -> removeItem(pb->petLayout);
    }
}

void Widget::showNurseMenu()
{
    bool show = isShowing[nurse];
    for (int i = 0; i < 4; i++){
        hideMenu(i);
        isShowing[i] = false;
    }
    if (!show)
    {
        isShowing[nurse] = true;
        mainLayout -> insertLayout(mainLayout->count()-1, nb->nurseLayout);
        nb->showLayout();
    }
    else
    {
        isShowing[nurse] = false;
        nb->hideLayout();
        mainLayout -> removeItem(nb->nurseLayout);
    }
}

void Widget::hideMenu(int i)
{
    switch (i){
        case stat:
        stats ->hide();
        mainLayout -> removeWidget(stats);
        break;

        case feed:
        fb->hideLayout();
        mainLayout -> removeItem(fb->feedLayout);
        break;

        case pet:
        pb->hideLayout();
        mainLayout -> removeItem(pb->petLayout);
        break;

        case nurse:
        nb->hideLayout();
        mainLayout -> removeItem(nb->nurseLayout);
        break;
    }
}

void Widget::paintEvent(QPaintEvent * pe)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    p.drawImage(QPoint(x,300), arr[petState]);
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == 1)
        this->spriteUpdate();
    if(event->timerId() == 2)
        ThePet->Update();
}

void Widget::spriteUpdate()
{
    if (moving == left){
        if (--x < minX){
            x = minX;
            moving = right;
            petState = 3;
        }
        else if (++petState > 2)
                petState = 0;
    }
    else{
        if (++x > maxX){
            x = maxX;
            moving = left;
            petState = 0;
        }
        else if (++petState > 5)
                petState = 3;
    }
    update();
}

Widget::~Widget()
{

}
