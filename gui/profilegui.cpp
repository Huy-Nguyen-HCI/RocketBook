#include "profilegui.h"
#include "ui_profilegui.h"

ProfileGUI::ProfileGUI(AccountController *inputAccountController, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfileGUI)
{
    ui->setupUi(this);
    accountController = inputAccountController;
}

ProfileGUI::~ProfileGUI()
{
    delete ui;
}



void ProfileGUI::loadProfile() {

    Profile *currentProfile = accountController->getUser()->getProfile();

    QString descr = currentProfile->getDescription();
    QString myName = currentProfile->getFullName();

    ui->descriptionBox->setText(descr);
    ui->username->setText("Username: " + myName);
}


void ProfileGUI::on_selectPicture_clicked()
{

}

void ProfileGUI::on_saveDescription_clicked()
{
    QString newDescription = ui->descriptionBox->toPlainText();
    if (accountController->getUser()->changeProfileDescription(newDescription)) {
        ui->message->setText("Update description successful!");
    }
    else {
        ui->message->setText("Update failed. Please call technical support.");
    }
}
