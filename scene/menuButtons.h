#ifndef MENUBUTTONS_H
#define MENUBUTTONS_H
#include <QtGui>
#include <QtWidgets>
#include <scene/pet.h>

class menuButton : public QPushButton
{
    Q_OBJECT
public:
    explicit menuButton(QWidget *parent = nullptr) : QPushButton(parent)
    { setIconSize(QSize(32,32)); }

    QVBoxLayout * menuLayout;
    virtual void hideLayout() {}
    virtual void showLayout() {}

protected:
    Pet & ThePet = Pet::getInstance();

};

class feedButton : public menuButton
{
    Q_OBJECT
public:
    explicit feedButton(QWidget *parent = nullptr);
    void hideLayout();
    void showLayout();

private:
    QPushButton * tacoButton;
    QPushButton * pieButton;
    QPushButton * juiceButton;
};


class nurseButton : public menuButton
{
    Q_OBJECT
public:
    explicit nurseButton(QWidget *parent = nullptr);
    void hideLayout();
    void showLayout();

private:
    QPushButton * pillButton;
    QPushButton * injectionButton;

};

class petButton : public menuButton
{
    Q_OBJECT
public:
    explicit petButton(QWidget *parent = nullptr);
    void hideLayout();
    void showLayout();

private:
    QPushButton * brushButton;
    QPushButton * hugButton;
    QPushButton * ballButton;
};

class statsButton : public menuButton
{
    Q_OBJECT
public:
    explicit statsButton(QWidget *parent = nullptr);
    void hideLayout();
    void showLayout();

private:
    QLabel * stats;
};

class cleanButton : public menuButton
{
    Q_OBJECT
public:
    explicit cleanButton(QWidget *parent = nullptr);
};

#endif // MENUBUTTONS_H
