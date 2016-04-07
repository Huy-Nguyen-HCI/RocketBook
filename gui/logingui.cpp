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


void LoginGUI::on_loginButton_clicked()
{

}

void LoginGUI::on_createAccountButton_clicked()
{

}
