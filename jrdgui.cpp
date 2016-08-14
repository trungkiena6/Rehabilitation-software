#include "jrdgui.h"
#include "ui_jrdgui.h"

JrdGui::JrdGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::JrdGui)
{
    ui->setupUi(this);
}

JrdGui::~JrdGui()
{
    delete ui;
}
