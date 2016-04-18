#include "createaccountgui.h"
#include "ui_createaccountgui.h"

CreateAccountGUI::CreateAccountGUI(AccountController *input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateAccountGUI)
{
    ui->setupUi(this);
    accountController = input;
}

CreateAccountGUI::~CreateAccountGUI()
{
    delete ui;
}

/**
 * @brief CreateAccountGUI::on_uploadButton_clicked allows the user to pick a file to upload.
 */
void CreateAccountGUI::on_uploadButton_clicked()
{

}

/**
 * @brief CreateAccountGUI::on_returnButton_clicked returns to the login GUI
 */
void CreateAccountGUI::on_returnButton_clicked()
{
    this->close();
    loginView->clearAllFields();
    loginView->show();
}

/**
 * @brief CreateAccountGUI::on_createButton_clicked process creating a new account
 */
void CreateAccountGUI::on_createButton_clicked()
{
    QString username = ui->usernameBox->text();
    QString password = ui->passwordBox->text();
    QString confirm = ui->confirmPasswordBox->text();
    QString fullName = ui->fullnameBox->text();
    QString photo = ui->profilePathBox->text();
//    QString description = ui->describeBox->;

    // check username and password cannot be empty

    if (username.isEmpty() || password.isEmpty()) {

         ui->message->setText("Error: Both username and password have to be nonempty!");

         return;
    }

    // check username in database
    if (accountController->checkAccountExists(username)) {

        ui->message->setText("Error: Account already exists!");

        return;
    }

    // check passwords match
    if (password != confirm) {

        ui->message->setText("Passwords do not match!");

        return;
    }

    // check name field
    if (fullName.isEmpty()) {

        ui->message->setText("Name cannot be empty!");

        return;
    }

    // if username does not exist, create account and display successful message
    if (accountController->createNewAccount(username, password, fullName, photo)) {

        ui->message->setText("Create account " + username + " successful!");

    }
    else
        ui->message->setText("Error occured while trying to create new account.");

}

void CreateAccountGUI::clearAllFields() {
    ui->usernameBox->setText("");
    ui->passwordBox->setText("");
    ui->confirmPasswordBox->setText("");
    ui->fullnameBox->setText("");
    ui->profilePathBox->setText("");
    ui->describeBox->document()->setPlainText("");
    ui->message->setText("");
}