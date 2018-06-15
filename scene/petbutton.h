#ifndef PETBUTTON_H
#define PETBUTTON_H

#include <QPushButton>
#include <scene/pet.h>

class petButton : public QPushButton
{
    Q_OBJECT
public:
    explicit petButton(Pet * ThePet, QWidget *parent = nullptr);

signals:

public slots:

private:
    QMenu * petMenu;
};

#endif // PETBUTTON_H
