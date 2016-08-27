#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include "dbdatalog.h"
static const QString path = "/home/hung303mc/JRDProject/SideScrollerGame/JRD";


class MyRect: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    MyRect(QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent *event);
    DbDataLog * db;
private:
    QMediaPlayer * bulletsound;
public slots:
    void spawn();
    void gameOver();
    void test();
};


#endif // MYRECT_H
