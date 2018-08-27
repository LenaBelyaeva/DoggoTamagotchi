#include "graphicsManager.h"
#include <QtGui>
#include <QtWidgets>
#include <scene/mainScene.h>

GraphicsManager::GraphicsManager(Scene scene) : _scene(scene)
{
    if (scene == Main){
        petMaxX = MainScene::WIDTH;
        petY = 300;

        for (unsigned int i = 0; i < 3; i++)
            poopSprites[i] = QImage(sprites[Poop + i].c_str());

        poopMaxX = MainScene::WIDTH - poopSprites[0].width();
        poopMinX = 0;
        poopMinY = petY - poopSprites[0].width()/2;
        poopMaxY = MainScene::HEIGHT - poopSprites[0].width();
    }
}

bool GraphicsManager::addObject(GraphicsManager::Object obj)
{
    if (obj >= WhiteDoggo && obj < Poop ){
        for (unsigned int i = 0; i < 6; i++)
            petSprites[i] = QImage(sprites[obj + i].c_str());

        petMinX = -petSprites[0].width();
        petX = (petMaxX+petMinX)/2;
        petMovingDirection = left;
        petSpriteIndex = 0;
        petIsSet = true;
        return true;
    }
    else if ( obj == Poop && poopCounter < Pet::MAX_POOPS_COUNT){
        poopCounter++;
        int x = rand() % ((poopMaxX + 1) - poopMinX) + poopMinX;
        int y = rand() % ((poopMaxY + 1) - poopMinY) + poopMinY;
        int deltaY = (y + poopSprites[0].height() - petY - petSprites[0].height());
        if (deltaY >= 0 && deltaY < 5)
            y = petY + 5;
        int index = qrand() % 3;
        poopsX.push_back(x);
        poopsY.push_back(y);
        poopsSpriteIndex.push_back(index);
        return true;
    }

    return false;

}

void GraphicsManager::spritesUpdate()
{
    petSpriteUpdate();

    Pet & thePet = Pet::getInstance();
    while (thePet.getPoops() != poopCounter){
        if (thePet.getPoops() < poopCounter)
            removeObject(Object::Poop);
        if (thePet.getPoops() > poopCounter)
            addObject(Object::Poop);

    }

    for (unsigned int i = 0; i < poopsSpriteIndex.size(); i++){
        if (++(poopsSpriteIndex[i]) == 3)
            poopsSpriteIndex[i] = 0;
    }
}

void GraphicsManager::removeObject(GraphicsManager::Object obj)
{
    if (obj == Poop){
        if (poopCounter == 0)
            return;
        poopsX.pop_back();
        poopsY.pop_back();
        poopsSpriteIndex.pop_back();
        poopCounter--;
    }
}

//that's really bad
std::vector<std::pair<QPoint, QImage>> GraphicsManager::getCoordAndSprites(){

    std::vector<std::pair<QPoint, QImage>> coordAndSprites;
    if (petIsSet){
        QPoint coordinates(petX, petY);
        coordAndSprites.push_back(std::pair<QPoint, QImage>(coordinates, petSprites[petSpriteIndex]));
    }
    for (int i = 0; i < poopCounter; i++){
        QPoint coordinates(poopsX[i], poopsY[i]);
        QImage & sprite = poopSprites[poopsSpriteIndex[i]];
        coordAndSprites.push_back(std::pair<QPoint, QImage>(coordinates, sprite));
    }

    std::sort(coordAndSprites.begin(), coordAndSprites.end(),
                  [](const coordSprite & a, const coordSprite & b ) -> bool
                  { return a.first.y() < b.first.y(); });

    return std::move(coordAndSprites);
}

void GraphicsManager::petSpriteUpdate()
{
    if (petMovingDirection == left){
        if (--petX < petMinX){
            petX = petMinX;
            petMovingDirection = right;
            petSpriteIndex = 3;
        }
        else if (++petSpriteIndex > 2)
                petSpriteIndex = 0;
    }
    else {
        if (++petX > petMaxX){
            petX = petMaxX;
            petMovingDirection = left;
            petSpriteIndex = 0;
        }
        else if (++petSpriteIndex > 5)
                petSpriteIndex = 3;
    }
}
