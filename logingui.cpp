#include "logingui.h"
#include "ui_logingui.h"

LoginGUI::LoginGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginGUI)
{
    ui->setupUi(this);
}

LoginGUI::~LoginGUI()
{
    delete ui;
}
