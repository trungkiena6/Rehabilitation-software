#include "game.h"
#include "myrect.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QWidget>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <QPushButton>
#include <QDialog>

/*
    Add scene:  add player into it
    Add player item: make it focusable, set it position
    Add view (display scene): show it, set its size
    Add enemy:
*/
Game::Game()
{
    // add the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/image/bg.png")));
    scene2 = new QGraphicsScene();
    scene2->setSceneRect(0,0,800,600);

    // add view + scene to view
    setScene(scene);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    /**************
    *   Scene game
    **************/
    // add player item + player to scene
    player = new MyRect();
    scene->addItem(player);
    // make player focusable 
    player->setFlags(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->setPos(width()/2 - player->pixmap().width()/2,
                   height()/2 - player->pixmap().height()/2);

    // add score
    score = new Score();
    scene->addItem(score);

    // add health
    health = new Health();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);

    // spawn enemy
    timerEnemy = new QTimer();
    QObject::connect(timerEnemy,SIGNAL(timeout()),player,SLOT(spawn()));


    // Setting timer for GameOver
    timerOver = new QTimer();
    QObject::connect(timerOver,SIGNAL(timeout()),player,SLOT(gameOver()));

    //add Arduino Serialport
    arduino = new MySerial();
    qDebug() <<"serial port: "<< arduino->portName();
    QObject::connect(arduino,SIGNAL(readyRead()),arduino,SLOT(readSerial()));
    timerTest = new QTimer();
    QObject::connect(timerTest,SIGNAL(timeout()),player,SLOT(test()));




    // play back ground music
//    QMediaPlayer * music = new QMediaPlayer();
//    music->setMedia(QUrl("qrc:/sound/noemotion.mp3"));
//    music->play();
//    show();
}

void Game::gameStart()
{
    setScene(scene);
    timerEnemy->start(5000);
    timerOver->start(1000*20);
    timerTest->start(50);
}
