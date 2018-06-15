#ifndef FEEDBUTTON_H
#define FEEDBUTTON_H


#include <QtGui>
#include <QtWidgets>
#include <scene/pet.h>

class feedButton : public QPushButton
{
    Q_OBJECT
public:
    explicit feedButton(Pet * ThePet, QWidget *parent = nullptr);

signals:

public slots:

private:
    QMenu *feedMenu;
};

#endif // FEEDBUTTON_H
