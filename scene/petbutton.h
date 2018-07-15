#ifndef PETBUTTON_H
#define PETBUTTON_H

#include <QPushButton>
#include <scene/pet.h>

class petButton : public QPushButton
{
    Q_OBJECT
public:
    explicit petButton(Pet * ThePet, QWidget *parent = nullptr);
    QVBoxLayout * petLayout;
    void hideLayout();
    void showLayout();


signals:

public slots:

private:
    QPushButton * brushButton;
    QPushButton * hugButton;
    QPushButton * ballButton;
};

#endif // PETBUTTON_H
