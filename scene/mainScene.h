#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include <QtWidgets>
#include <scene/pet.h>
#include <scene/mainSceneMenu.h>
#include <scene/graphicsManager.h>

class MainScene : public QWidget
{
    Q_OBJECT
public:
    MainScene(QWidget *parent = 0);
    ~MainScene() = default;

    static QString mainFontFamily;
    static const int WIDTH = 278;
    static const int HEIGHT = 367;

private:
    const int MILISEC_PER_FRAME = 200;
    const int MILISEC_PER_UPDATE = 60000;

    Pet & ThePet = Pet::getInstance();
    GraphicsManager manager;
    MainSceneMenu * mainMenu;

protected:
    void paintEvent(QPaintEvent *pe);
    void timerEvent(QTimerEvent *event);
};

#endif // WIDGET_H
