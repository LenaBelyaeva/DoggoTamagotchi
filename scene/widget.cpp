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
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->setAlignment(Qt::AlignTop);
    buttonLayout->addWidget(sb);
    buttonLayout->addWidget(fb);
    buttonLayout->addWidget(cb);
    buttonLayout->addWidget(pb);
    buttonLayout->addWidget(nb);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addStretch();

    int id = QFontDatabase::addApplicationFont(":/fonts/ARCADECLASSIC.TTF");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont arcade(family, 12);

    stats = new QLabel;
    stats->setFont(arcade);
    stats->setAlignment(Qt::AlignCenter);

    QImage wl1(":/img/icons/walk-left-1.png");
    QImage wl2(":/img/icons/walk-left-2.png");
    QImage wl3(":/img/icons/walk-left-3.png");
    QImage wr1(":/img/icons/walk-right-1.png");
    QImage wr2(":/img/icons/walk-right-2.png");
    QImage wr3(":/img/icons/walk-right-3.png");
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

    startTimer(200);
    startTimer(60000);
}

void Widget::showStats()
{
    static int show = -1;
    show *= (-1);
    if (show == 1)
    {
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
    }
    else
    {
        stats ->hide();
        mainLayout -> removeWidget(stats);
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
