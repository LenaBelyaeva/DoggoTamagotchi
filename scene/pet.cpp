#include "pet.h"
#include <QtGui>
#include <QtWidgets>

Pet::Pet()
{
    died = false;
    age = 0;
    health = 100;
    happiness = 100;
    poops = 0;
    hungry = 100;
    speedAge = 1;
    speedHealth = 0;
    speedHappiness = -10;
    speedPoops = 1;
    speedHungry = -10;
}

void Pet::giveTaco()
{
    hungry += 20;
    if (hungry > 100){
        health -= 5;
        if (health  < 0)
            died = true;
        hungry = 100;
    };
}


void Pet::givePie()
{
    hungry += 30;
    if (hungry > 100){
        health -= 5;
        if (health  < 0)
            died = true;
        hungry = 100;
    };
}

void Pet::giveJuice()
{
    hungry += 5;
    if (hungry  > 100){
        health -= 5;
        if (health  < 0)
            died = true;
        hungry = 100;
    };
}

void Pet::givePill()
{
    happiness -= 5;
    if(happiness < 0)
        happiness = 0;
    health += 5;
    if (health  > 100)
        health = 100;
}

void Pet::giveInjection()
{
    happiness -= 10;
    if(happiness  < 0)
        happiness = 0;
    health += 10;
    if (health  > 100)
        health = 100;
}

void Pet::giveBrush()
{
    happiness += 5;
    if(happiness > 100)
        happiness = 100;
}

void Pet::giveHug()
{
    happiness += 10;
    if(happiness > 100)
        happiness = 100;
}

void Pet::giveBall()
{
    happiness += 15;
    if(happiness > 100)
        happiness = 100;
}

void Pet::clean()
{
    if(--poops < 0)
        poops = 0;
}

int Pet::getHungry() const
{
    return hungry;
}

int Pet::getHealth() const
{
    return health;
}

int Pet::getAge() const
{
    return age;
}

int Pet::getPoops() const
{
    return poops;
}

int Pet::getHappiness() const
{
    return happiness;
}

void Pet::Update()
{
    if (died)
        return;

    age += speedAge;
    if (poops > 2 && speedHealth > -30)
        speedHealth -= 5;
    if (hungry > 40 && hungry < 60 && speedHealth > -30){
        speedHealth -= 1;
        if(speedHappiness > -30)
            speedHappiness -= 5;
    }
    if (hungry < 40 && speedHealth > -30)
    {
        speedHealth -= 5;
    }

    if (hungry == 100 && health == 100 && poops == 0 && happiness == 100){
        speedHealth = 0;
        speedHappiness = -10;
    }
    if (poops < 5)
        poops += speedPoops;
    if (health > (-1)*speedHealth)
        health += speedHealth;
    if (happiness > (-1)*speedHappiness )
        happiness += speedHappiness;
    if (hungry > (-1)*speedHungry)
        hungry += speedHungry;

    if ( hungry < (-1)*speedHungry || health < (-1)*speedHealth)
        died = true;

}
