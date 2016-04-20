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

void ProfileGUI::on_pushButton_loadProfile_clicked()
{
    Profile *currentProfile = accountController->getUser().getProfile();


}
