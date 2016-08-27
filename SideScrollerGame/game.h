#ifndef GAME_H
#define GAME_H
#include "player.h"
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
    Player * player;
    Score *score;
    Health * health;
    int StateCollide;
    QTimer * timerEnemy;
    MySerial *arduino;
    QTimer * timerOver;
    QTimer * timerTest;

public slots:
    void gameStart();
    void gameOver();
private:
};

#endif // GAME_H
