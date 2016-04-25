#include "creategroupgui.h"
#include "ui_creategroupgui.h"

CreateGroupGUI::CreateGroupGUI(AccountController *inputAccountController, GroupGUI* groupGUI, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateGroupGUI)
{
    ui->setupUi(this);
    this->groupGUI = groupGUI;
    this->accountController = inputAccountController;
}

CreateGroupGUI::~CreateGroupGUI()
{
    delete ui;
}

void CreateGroupGUI::on_buttonBox_accepted()
{
    //retrieve the group details
    QString fullName = ui->fullNameInput->text();
    QString photo = ui->photoFilePathInput->text();
    QString description = ui->descriptionInput->document()->toPlainText();
    Group* currentGroup = accountController->getUser()->controlGroup()->createNewGroup(fullName, photo, description);

    //add group members
    QList<QListWidgetItem*> memberList = ui->friendList->selectedItems();
    for (int i = 0; i < memberList.size(); i++) {
        QString memberUsername = memberList.at(i)->text();
        currentGroup->addMember(memberUsername);
    }
    groupGUI->switchGroupViews();
}

void CreateGroupGUI::on_buttonBox_rejected()
{
    clearAllFields();
    groupGUI->switchGroupViews();
}

void CreateGroupGUI::clearAllFields()
{
    ui->fullNameInput->clear();
    ui->photoFilePathInput->clear();
    ui->descriptionInput->clear();
    ui->friendList->clearSelection();
}
