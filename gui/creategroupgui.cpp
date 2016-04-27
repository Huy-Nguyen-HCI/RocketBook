#include "creategroupgui.h"
#include "ui_creategroupgui.h"

CreateGroupGUI::CreateGroupGUI(AccountController *inputAccountController, GroupGUI* groupGUI, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateGroupGUI)
{
    ui->setupUi(this);
    this->groupGUI = groupGUI;
    this->accountController = inputAccountController;
    clearAllFields();
    updateFriendList();
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
    QModelIndexList memberList = ui->friendList->selectionModel()->selectedIndexes();
    for (int i = 0; i < memberList.size(); i++) {
        QString memberUsername = memberList.at(i).data().toString();
        currentGroup->addMember(memberUsername);
    }

    clearAllFields();
    updateFriendList();

    groupGUI->switchGroupViews(GroupGUI::GroupGUIType::ShowAllGroups);
}

void CreateGroupGUI::on_buttonBox_rejected()
{
    clearAllFields();
    updateFriendList();
    groupGUI->switchGroupViews(GroupGUI::GroupGUIType::ShowAllGroups);
}

void CreateGroupGUI::clearAllFields()
{
    ui->fullNameInput->clear();
    ui->photoFilePathInput->clear();
    ui->descriptionInput->clear();
    ui->friendList->clearSelection();
}

void CreateGroupGUI::updateFriendList()
{
    ui->friendList->setSelectionMode(QAbstractItemView::ExtendedSelection);
    FriendController* friendCtrl = accountController->getUser()->controlFriend();
    friendCtrl->updateFriendList();
    QStringList friends = friendCtrl->getFriendNames();
    QStringListModel *model = new QStringListModel(friends);
    ui->friendList->setModel(model);
    //Prevents user for editing friendlist entries in qlist manually
    ui->friendList->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
