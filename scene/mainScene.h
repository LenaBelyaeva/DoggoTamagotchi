#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include <QtWidgets>
#include <scene/pet.h>
#include <scene/menuButtons.h>

#define left -1
#define right 1

class MainScene : public QWidget
{
    Q_OBJECT
public:
    MainScene(QWidget *parent = 0);
    ~MainScene() = default;

    static QString mainFontFamily;

private:
    const int MILISEC_PER_FRAME = 200;
    const int MILISEC_PER_UPDATE = 60000;

    Pet & ThePet = Pet::getInstance();

    QImage petSprites[6];
    int x;
    int movingDirection;
    int maxX;
    int minX;
    int petState;
    void spriteUpdate();

    QVBoxLayout * mainLayout;

    menuButton * menuButtons[5];

    enum Menu {stat, feed, pet, nurse, none};
    Menu currentMenu = none;
    void showButtonLayout(menuButton * mb);
    void hideButtonLayout(menuButton * mb);

public slots:
    void showMenu();

protected:
    void paintEvent(QPaintEvent *pe);
    void timerEvent(QTimerEvent *event);
};

#endif // WIDGET_H
