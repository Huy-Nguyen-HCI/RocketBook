#include "logingui.h"
#include "ui_logingui.h"

LoginGUI::LoginGUI(AccountDB *inputAccountDB, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginGUI)
{
    ui->setupUi(this);
    accountDB = inputAccountDB;
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
    if (accountDB->accountExists(username)) {

        // get all the info about the account with the input username
        AccountInfoType info = accountDB->retrieveAccountInfo(username, password);

        QString storedPassword = AccountDB::getAccountPassword(info);

        /// TODO: if username and password match, log in and segue to main view
        if (storedPassword == password) {
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
    if (accountDB->accountExists(username)) {

        ui->message->setText("Error: Account already exists!");
    }
    // if username does not exist, create account and display successful message
    else {
        //check what is the last ID of the rocketuser in the database, create the ID for the next user
        int rocketUserID = accountDB->getMaxAccountID() + 1;
        /// TODO: do something about profileID
        accountDB->addAccount(rocketUserID, username, password, 100 );
        ui->message->setText("Create account " + username + " successful!");
    }

}
