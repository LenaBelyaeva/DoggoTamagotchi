#include "statsbutton.h"
#include <QtGui>
#include <QtWidgets>
#include <QMessageBox>

statsButton::statsButton(Pet * ThePet, QWidget *parent) : QPushButton(parent)
{
    setIcon(QIcon(":/img/icons/Clipboard.png"));
    setIconSize(QSize(32,32));
    //statsBox = new QMessageBox;
    //QPushButton * OkButton = statsBox->addButton(QMessageBox::Ok);
    //statsBox->setText("kek");
    //feedMenu->setLayout();
    //connect(this, SIGNAL(clicked()), this, SLOT(showStats(ThePet)));

}

