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
    QString username = ui->usernameBox->text();
    QString password = ui->passwordBox->text();

    // if username and password match, log in and segue to main view

    // else, display error message
    ui->message->setText("Error: Wrong username or password!");
}

void LoginGUI::on_createAccountButton_clicked()
{
    QString username = ui->usernameBox->text();
    QString password = ui->passwordBox->text();

    // check username

    // if username does not exist, create account and display successful message
    ui->message->setText("Create account successful!");

    /*
     * CREATE ACCOUNT
     */

    // else, display error message
    ui->message->setText("Error: Username already exists!");
}
