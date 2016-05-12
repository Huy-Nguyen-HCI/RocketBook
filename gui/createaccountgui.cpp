#include "createaccountgui.h"
#include "ui_createaccountgui.h"

CreateAccountGUI::CreateAccountGUI(AccountController *input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateAccountGUI)
{
    ui->setupUi(this);
    accountController = input;
    ui->passwordBox->setEchoMode(QLineEdit::Password);
    ui->confirmPasswordBox->setEchoMode(QLineEdit::Password);
}

CreateAccountGUI::~CreateAccountGUI()
{
    delete ui;
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
    QString description = ui->describeBox->document()->toPlainText();    
    QString serverPath = AccountController::PATH + "picturesDir/" + username + "Pic";

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

    // if username does not already exist, create account, copy image, and segue to dashboard
    if (accountController->createNewAccount(username, password, fullName, serverPath, description)) {

        // copy the image to the server
        QFile::copy(photoPath, serverPath);

        // segue to dashboard
        this->close();
        accountController->login(username, password);
        main->setUsername(username);
        main->setUp();
        main->show();
        return;

    }

    // display error message
    ui->message->setText("Error occured while trying to create new account.");

}

void CreateAccountGUI::clearAllFields() {
    ui->usernameBox->clear();
    ui->passwordBox->clear();
    ui->confirmPasswordBox->clear();
    ui->fullnameBox->clear();
    ui->profilePathBox->clear();
    ui->describeBox->document()->clear();
    ui->message->clear();
}

/**
 * @brief CreateAccountGUI::on_uploadButton_clicked allows the user to pick a file to upload.
 */
void CreateAccountGUI::on_uploadButton_clicked(){

    photoPath = QFileDialog::getOpenFileName(this,
                                             tr("Pick your image"),
                                             ":/",
                                             tr("Image Files (*.png *.jpg *.bmp)"));
    // if user cancels the file selection
    if (photoPath.isNull()) {
        return;
    }

    // display the selected path
    ui->profilePathBox->setText(photoPath);
}


