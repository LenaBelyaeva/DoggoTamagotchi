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
    static const int MAX_POOPS_COUNT = 15;
    void Update();
    int getHungry() const;
    int getHealth() const;
    int getAge() const;
    int getPoops() const;
    int getHappiness() const;
    int isDied() const;

    static Pet& getInstance(){
        static Pet instance;
        return instance;
    }

private:
    Pet();
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

    Pet(Pet const &);
    void operator=(Pet const &);
};

#endif // PET_H
