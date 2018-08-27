#ifndef MAINSCENEMENU_H
#define MAINSCENEMENU_H
#include "scene/menubuttons.h"
#include <QtGui>
#include <QtWidgets>
#include <scene/pet.h>

class MainSceneMenu : public QVBoxLayout
{
    Q_OBJECT
public:
    explicit MainSceneMenu(QWidget *parent = nullptr);

private:
    menuButton * menuButtons[5];
    enum Menu {stat, feed, pet, nurse, none};
    Menu currentMenu = none;
    void showButtonLayout(menuButton * mb);
    void hideButtonLayout(menuButton * mb);

public slots:
    void showMenu();
};

#endif // MAINSCENEMENU_H
