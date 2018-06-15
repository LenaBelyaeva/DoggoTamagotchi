#ifndef CLEANBUTTON_H
#define CLEANBUTTON_H

#include <QPushButton>
#include <scene/pet.h>

class cleanButton : public QPushButton
{
    Q_OBJECT
public:
    explicit cleanButton(Pet * ThePet, QWidget *parent = nullptr);

signals:

public slots:

private:
    QMenu *cleanMenu;
};

#endif // CLEANBUTTON_H
