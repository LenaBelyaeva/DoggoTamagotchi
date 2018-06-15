#ifndef PET_H
#define PET_H
#include <QObject>
#include <QtGui>
#include <QtWidgets>


class Pet : public QObject
{
    Q_OBJECT
public slots:
    void giveTaco();
    void givePie();
    void giveJuice();
    void giveBrush();
    void giveHug();
    void giveBall();
    void givePill();
    void giveInjection();
    void clean();
public:
    Pet();
    ~Pet();
    void Update();
    int getHungry() const;
    int getHealth() const;
    int getAge() const;
    int getPoops() const;
    int getHappiness() const;
    int isDied() const;
private:
    bool died;
    int age;
    int speedAge;
    int hungry;
    int speedHungry;
    int health;
    int speedHealth;
    int poops;
    int speedPoops;
    int happiness;
    int speedHappiness;
};

#endif // PET_H
