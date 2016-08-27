#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList> // detect collide
#include "enemy.h"
#include <typeinfo>
#include "game.h"

/*
    Constructor: draw rect, connect(timer -> move())
    Move(): set position, keep in range
*/

extern Game *game;

Bullet::Bullet(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent){
    //draw rectangle
    setPixmap(QPixmap(":/image/bullet.png"));


    //connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

Bullet::~Bullet()
{

}

void Bullet::move()
{
    // if bullet collide enemy, destroy both
    QList<QGraphicsItem *> collide_item = collidingItems();
    for(int i=0, n= collide_item.size(); i<n;i++){
        if(typeid(* collide_item[i]) == typeid(Enemy)){
            // increase the score
            game->score->increase();

            //remove them both
            scene()->removeItem(collide_item[i]);
            scene()->removeItem(this);
            //delete them both
            delete collide_item[i];
            delete this;
            return;
        }
    }


    setPos(x(),y()-10);
    if(pos().y()<0){
        scene()->removeItem(this);
        delete this;
    }
}
