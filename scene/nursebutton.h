#ifndef NURSEBUTTON_H
#define NURSEBUTTON_H

#include <QtGui>
#include <QtWidgets>
#include <scene/pet.h>

class nurseButton : public QPushButton
{
    Q_OBJECT
public:
    explicit nurseButton(Pet * ThePet, QWidget *parent = nullptr);

signals:

public slots:

private:
    QMenu * nurseMenu;
};

#endif // NURSEBUTTON_H
