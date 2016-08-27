#include "jrdgui.h"
#include "ui_jrdgui.h"
#include "game.h"
#include <QObject>

extern Game * game;

JrdGui::JrdGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::JrdGui)
{
    ui->setupUi(this);
    game = new Game();
    game->setParent(ui->tabGame);
    QObject::connect(ui->buttonStart,SIGNAL(clicked(bool)),game,SLOT(gameStart()));
}

JrdGui::~JrdGui()
{
    delete ui;
}
