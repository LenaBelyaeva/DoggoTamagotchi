#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H
#include <QtGui>
#include <QtWidgets>
#include <string>

#define left -1
#define right 1
typedef std::pair<QPoint, QImage> coordSprite;

class GraphicsManager
{
public:
    enum Scene {Main};
    enum Object {WhiteDoggo = 0, Poop = 6};

    GraphicsManager(Scene scene);

    bool addObject(Object obj);
    void removeObject(Object obj);
    void spritesUpdate();
    std::vector<std::pair<QPoint, QImage>> getCoordAndSprites();

private:
    Scene _scene;

    bool petIsSet;
    QImage petSprites[6];
    int petX;
    int petMovingDirection;
    int petMaxX;
    int petMinX;
    int petY;
    int petSpriteIndex;
    void petSpriteUpdate();

    int poopCounter = 0;
    std::vector<int> poopsX;
    std::vector<int> poopsY;
    std::vector<int> poopsSpriteIndex;
    QImage poopSprites[3];
    int poopMaxX;
    int poopMinX;
    int poopMaxY;
    int poopMinY;

    std::string sprites[9] = {  ":/img/walk-left-1.png",
                                    ":/img/walk-left-2.png",
                                    ":/img/walk-left-3.png",
                                    ":/img/walk-right-1.png",
                                    ":/img/walk-right-2.png",
                                    ":/img/walk-right-3.png",
                                    ":/img/poop-1.png",
                                    ":/img/poop-2.png",
                                    ":/img/poop-3.png"};
};

#endif // GRAPHICSMANAGER_H
