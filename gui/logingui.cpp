#include "logingui.h"
#include "ui_logingui.h"

LoginGUI::LoginGUI(AccountController *inputAccountController, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginGUI)
{
    ui->setupUi(this);
    accountController = inputAccountController;
}

LoginGUI::~LoginGUI()
{
    delete ui;
}


void LoginGUI::on_loginButton_clicked()
{
    QString username = ui->usernameBox->text();
    QString password = ui->passwordBox->text();

    // check username
    if (accountController->checkAccountExists(username)) {

        /// TODO: if username and password match, log in and segue to main view
        if (accountController->verifyPassword(username, password)) {
            ui->message->setText("Welcome, " + username + "!");
        }
        else {
            ui->message->setText("Error: Wrong password!");
        }
    }

    // display error message
    else
        ui->message->setText("Error: Account does not exist!");
}

void LoginGUI::on_createAccountButton_clicked()
{
    QString username = ui->usernameBox->text();
    QString password = ui->passwordBox->text();

    // check username
    if (accountController->checkAccountExists(username)) {

        ui->message->setText("Error: Account already exists!");
    }
    // if username does not exist, create account and display successful message
    else {
        if (accountController->createNewAccount(username, password)) {
            ui->message->setText("Create account " + username + " successful!");
        }
        else
            ui->message->setText("Error occured while trying to create new account.");
    }

}
