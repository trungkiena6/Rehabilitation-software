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
    /*************
    *   Tab Game
    *************/
    game = new Game();
    game->setParent(ui->tabGame);
    //button
    QObject::connect(ui->buttonStart,SIGNAL(clicked(bool)),game,SLOT(gameStart()));
    //button mode game
    QObject::connect(ui->buttonEnablePlayer,SIGNAL(clicked(bool)),game,SLOT(mybuttonClick1()));
    QObject::connect(ui->buttonDisablePlayer,SIGNAL(clicked(bool)),game,SLOT(mybuttonClick2()));
    QObject::connect(ui->buttonRunPlayer,SIGNAL(clicked(bool)),game,SLOT(mybuttonClick3()));
    QObject::connect(ui->buttonMode1Player,SIGNAL(clicked(bool)),game,SLOT(mybuttonClick4()));
    QObject::connect(ui->buttonMode3Player,SIGNAL(clicked(bool)),game,SLOT(mybuttonClick5()));
    QObject::connect(ui->buttonStopPlayer,SIGNAL(clicked(bool)),game,SLOT(mybuttonClick6()));
}

JrdGui::~JrdGui()
{
    delete ui;
}
