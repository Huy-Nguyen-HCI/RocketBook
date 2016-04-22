#include "logingui.h"
#include "ui_logingui.h"

bool LoginGUI::finished = false;

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

        // if username and password match, log in and segue to main view
        if (accountController->login(username, password)) {
            this->close();
            main->setUsername(username);
            main->show();
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

    this->close();
    createAccountView->clearAllFields();
    createAccountView->show();

}

void LoginGUI::clearAllFields() {
    ui->usernameBox->setText("");
    ui->passwordBox->setText("");
    ui->message->setText("");
}

void LoginGUI::on_quitButton_clicked()
{
    finished = true;
    this->close();
}
