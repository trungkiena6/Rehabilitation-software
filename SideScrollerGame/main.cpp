#include <QApplication>
#include "game.h"



Game * game;
// Set valid db path before first run


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game();
    game->show();

    return a.exec();
}
