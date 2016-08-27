#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include "enemy.h"
#include <stdlib.h>
#include "friend.h"
#include "game.h"
#include "dbdatalog.h"


extern Game * game;

Player::Player(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    // draw a player
    setPixmap(QPixmap(":/image/player.png"));
}

void Player::keyPressEvent(QKeyEvent * event){
//    if (event->key() == Qt::Key_Up){
//        setPos(x(),y()-10);
//    }
//    else if (event->key() == Qt::Key_Down){
//        setPos(x(),y()+10);
//    }
}

void Player::spawn()
{
    // set random position
    int random_number = rand() % 200;
    // Create upper pipe + add into scene
    Enemy * upperPipe = new Enemy();
    upperPipe->setTransformOriginPoint(upperPipe->pixmap().width()/2, upperPipe->pixmap().height()/2);
    upperPipe->setRotation(180);
    upperPipe->setPos(800,-200+random_number);
    scene()->addItem(upperPipe);
    // create lower pipe + add into the scene
    Enemy * lowerPipe = new Enemy();
    lowerPipe->setPos(800,300+random_number);
    scene()->addItem(lowerPipe);
    // create friend between 2 pipe + add into the scene
    Friend * betweenSpace = new Friend();
    betweenSpace->setPos(800,100+random_number);
    scene()->addItem(betweenSpace);
}

void Player::test()
{
    int y_player = game->arduino->serialValue.toInt();
    y_player = y_player*600/1000;
    game->player->setPos(game->player->x(),y_player);
}
