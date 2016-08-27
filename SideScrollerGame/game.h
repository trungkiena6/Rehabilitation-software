#ifndef GAME_H
#define GAME_H
#include "myrect.h"
#include <QGraphicsView>
#include "score.h"
#include "health.h"
#include "myserial.h"
#include <QTimer>
#include <QDialog>
class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game();
    QGraphicsScene * scene;
    QGraphicsScene * scene2;
    QGraphicsScene * sceneStart;
    MyRect * player;
    Score *score;
    Health * health;
    int StateCollide;
    QTimer * timerEnemy;
    MySerial *arduino;
    QTimer * timerOver;
    QTimer * timerTest;

public slots:
    void gameStart();

private:
};

#endif // GAME_H
