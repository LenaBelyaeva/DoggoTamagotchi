#include <QtGui>
#include <QtWidgets>
#include "mainScene.h"
#include "pet.h"
#include "mainSceneMenu.h"
#include "graphicsManager.h"

QString MainScene::mainFontFamily;

MainScene::MainScene(QWidget *parent)
    : QWidget(parent), manager(GraphicsManager::Scene::Main)
{
    int id = QFontDatabase::addApplicationFont("://fonts/ARCADECLASSIC.TTF");
    mainFontFamily = QFontDatabase::applicationFontFamilies(id).at(0);

    setFixedSize(QSize(WIDTH,HEIGHT));

    mainMenu = new MainSceneMenu(this);

    manager.addObject(GraphicsManager::Object::WhiteDoggo);
//    for (int i = 0; i < 15; i++)
//        manager.addObject(GraphicsManager::Object::Poop);

    startTimer(MILISEC_PER_FRAME);
    startTimer(MILISEC_PER_UPDATE);
}

void MainScene::paintEvent(QPaintEvent * pe)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    auto coordAndSprites = manager.getCoordAndSprites();

    for (auto v = coordAndSprites.begin(); v != coordAndSprites.end(); v++ ){
        p.drawImage(v->first, v->second);
    }
}

void MainScene::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == 1){
        manager.spritesUpdate();
        update();
    }
    if(event->timerId() == 2)
        ThePet.Update();
}
