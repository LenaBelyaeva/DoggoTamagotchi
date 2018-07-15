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
    QVBoxLayout * feedLayout;
    void hideLayout();
    void showLayout();

signals:

public slots:

private:
    QPushButton * tacoButton;
    QPushButton * pieButton;
    QPushButton * juiceButton;
};

#endif // FEEDBUTTON_H
