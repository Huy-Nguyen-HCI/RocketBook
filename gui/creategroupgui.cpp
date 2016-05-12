#include "creategroupgui.h"
#include "ui_creategroupgui.h"

CreateGroupGUI::CreateGroupGUI(AccountController *inputAccountController, GroupGUI* groupGUI, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateGroupGUI)
{
    // set up the pointers
    ui->setupUi(this);
    this->groupGUI = groupGUI;
    this->accountController = inputAccountController;

    // refresh the view
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

    QString description = ui->descriptionInput->document()->toPlainText();

    //copy image to the server
    QString serverPath = AccountController::PATH + "picturesDir/" + fullName + "GroupPic";
    QFile::copy(photoPath, serverPath);

    Group* currentGroup = accountController->getUser()->controlGroup()->createNewGroup(fullName, serverPath, description);

    //add group members
    QModelIndexList memberList = ui->friendList->selectionModel()->selectedIndexes();
    for (int i = 0; i < memberList.size(); i++) {
        QString memberUsername = memberList.at(i).data().toString();
        currentGroup->addMember(memberUsername);
    }

    //refresh and clear fields
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
    // update the friend list in the model and controller
    ui->friendList->setSelectionMode(QAbstractItemView::ExtendedSelection);
    FriendController* friendCtrl = accountController->getUser()->controlFriend();
    friendCtrl->updateFriendList();

    // display the list in the view
    QStringList friends = friendCtrl->getFriendNames();
    QStringListModel *model = new QStringListModel(friends);
    ui->friendList->setModel(model);

    // prevent user from editing friendlist entries in qlist manually
    ui->friendList->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void CreateGroupGUI::on_uploadPhotoButton_clicked()
{
    photoPath = QFileDialog::getOpenFileName(this,
                                         tr("Pick your image"),
                                         ":/",
                                         tr("Image Files (*.png *.jpg *.bmp)"));
    // if user cancels the file selection
    if (photoPath.isNull()) {
        return;
    }

    ui->photoFilePathInput->setText(photoPath);

}
