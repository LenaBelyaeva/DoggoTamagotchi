#ifndef MENUBUTTONS_H
#define MENUBUTTONS_H
#include <QtGui>
#include <QtWidgets>
#include <scene/pet.h>
#include <scene/buttonEventWatcher.h>

class menuButton : public QPushButton
{
    Q_OBJECT
public:
    explicit menuButton(QWidget *parent = nullptr) : QPushButton(parent)
    { ButtonEventWatcher * watcher = new ButtonEventWatcher(this);
      this->installEventFilter(watcher);}

    QVBoxLayout * menuLayout;
    virtual void hideLayout() {}
    virtual void showLayout() {}

    virtual QIcon & getIcon() = 0;
    virtual QIcon & getIconHover() = 0;
    virtual QIcon & getIconPressed() = 0;

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
    virtual QIcon & getIcon() { return icon; }
    virtual QIcon & getIconHover() { return iconHover; }
    virtual QIcon & getIconPressed() { return iconPressed; }

private:
    QPushButton * tacoButton;
    QPushButton * pieButton;
    QPushButton * juiceButton;
    QIcon icon;
    QIcon iconHover;
    QIcon iconPressed;
};


class nurseButton : public menuButton
{
    Q_OBJECT
public:
    QIcon icon;
    QIcon iconHover;
    QIcon iconPressed;

    explicit nurseButton(QWidget *parent = nullptr);
    void hideLayout();
    void showLayout();
    virtual QIcon & getIcon() { return icon; }
    virtual QIcon & getIconHover() { return iconHover; }
    virtual QIcon & getIconPressed() { return iconPressed; }

private:
    QPushButton * pillButton;
    QPushButton * injectionButton;

};

class petButton : public menuButton
{
    Q_OBJECT
public:
    QIcon icon;
    QIcon iconHover;
    QIcon iconPressed;

    explicit petButton(QWidget *parent = nullptr);
    void hideLayout();
    void showLayout();
    virtual QIcon & getIcon() { return icon; }
    virtual QIcon & getIconHover() { return iconHover; }
    virtual QIcon & getIconPressed() { return iconPressed; }

private:
    QPushButton * brushButton;
    QPushButton * hugButton;
    QPushButton * ballButton;
};

class statsButton : public menuButton
{
    Q_OBJECT
public:
    QIcon icon;
    QIcon iconHover;
    QIcon iconPressed;

    explicit statsButton(QWidget *parent = nullptr);
    void hideLayout();
    void showLayout();
    virtual QIcon & getIcon() { return icon; }
    virtual QIcon & getIconHover() { return iconHover; }
    virtual QIcon & getIconPressed() { return iconPressed; }

private:
    QLabel * stats;
};

class cleanButton : public menuButton
{
    Q_OBJECT
public:
    QIcon icon;
    QIcon iconHover;
    QIcon iconPressed;

    explicit cleanButton(QWidget *parent = nullptr);
    virtual QIcon & getIcon() { return icon; }
    virtual QIcon & getIconHover() { return iconHover; }
    virtual QIcon & getIconPressed() { return iconPressed; }
};

#endif // MENUBUTTONS_H
