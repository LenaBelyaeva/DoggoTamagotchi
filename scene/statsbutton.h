#ifndef STATSBUTTON_H
#define STATSBUTTON_H
#include <QtGui>
#include <QtWidgets>
#include <scene/pet.h>

class statsButton : public QPushButton
{
    Q_OBJECT
public:
    explicit statsButton(Pet * ThePet, QWidget *parent = nullptr);

signals:

public slots:


private:
    QMessageBox *statsBox;
};

#endif // STATSBUTTON_H
