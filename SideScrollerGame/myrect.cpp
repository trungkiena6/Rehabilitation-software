#include "myrect.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include "enemy.h"
#include <stdlib.h>
#include "friend.h"
#include "game.h"
#include "dbdatalog.h"

extern Game * game;

MyRect::MyRect(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    // draw a player
    setPixmap(QPixmap(":/image/player.png"));
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sound/noemotion.mp3"));
}

void MyRect::keyPressEvent(QKeyEvent * event){
    if (event->key() == Qt::Key_Up){
        setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down){
        setPos(x(),y()+10);
    }
}

void MyRect::spawn()
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

void MyRect::gameOver()
{
    game->timerEnemy->stop();
    game->setScene(game->scene2);
//    db = new DbDataLog(path);
//    if(db->isOpen()){
//        db->WriteData(1,1,1);
//    }
//    else{
//        qDebug() << "khong zo duoc database";
//    }
}

void MyRect::test()
{
    int y_player = game->arduino->serialValue.toInt();
    y_player = y_player*600/1000;
    game->player->setPos(game->player->x(),y_player);
}
