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
    QVBoxLayout * nurseLayout;
    void hideLayout();
    void showLayout();

signals:

public slots:

private:
    QPushButton * pillButton;
    QPushButton * injectionButton;

};

#endif // NURSEBUTTON_H
