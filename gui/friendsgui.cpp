#include "friendsgui.h"
#include "ui_friendsgui.h"

FriendsGUI::FriendsGUI(AccountController *input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FriendsGUI)
{
    ui->setupUi(this);
    accountController = input;
}

FriendsGUI::~FriendsGUI()
{
    delete ui;
}

void FriendsGUI::on_viewProfile_clicked()
{
    QModelIndexList selected = ui->friendList->selectionModel()->selectedIndexes();
    if (selected.length() == 0) {
        ui->message->setText("Error: You have to select a friend to proceed.");
        return;
    }

    // get friend's info
    QString friendName = selected.at(0).data().toString();
    ProfileInfoType profile = accountController->getUser()->controlFriend()->getFriendProfile(friendName);

    // create a new dialog to view friend's profile
    FriendProfileGUI *friendProfile = new FriendProfileGUI(profile);
    friendProfile->show();
}

void FriendsGUI::on_removeFriend_clicked()
{
    QModelIndexList selected = ui->friendList->selectionModel()->selectedIndexes();
    if (selected.length() == 0) {
        ui->message->setText("Error: You have to select a friend to proceed.");
        return;
    }

    QString username = selected.at(0).data().toString();
    FriendController::DeleteFriendStatus status = accountController->getUser()->controlFriend()->deleteFriend(username);

    switch (status) {
    case FriendController::DeleteSuccessful:
        ui->message->setText("You and " + username + " are no longer friends.");
        refreshFriendList();
        break;
    case FriendController::FriendshipNotExist:
        ui->message->setText("Error: No friendship to remove. You have probably been ditched before you even know it.");
        refreshFriendList();
        break;
    default:
        ui->message->setText("Remove friend failed. Please call technical support.");
        break;
    }
}

void FriendsGUI::on_addFriend_clicked()
{
    QString friendName = ui->friendNameInput->text();
    FriendController::AddFriendStatus status = accountController->getUser()->controlFriend()->addFriend(friendName);

    switch (status) {
    case FriendController::AddSuccessful:
        ui->message->setText("Add friend successful!");
        refreshFriendList();
        break;

    case FriendController::FriendNotExist:
        ui->message->setText("Error: Input username does not exist.");
        break;

    case FriendController::AlreadyFriend:
        ui->message->setText("Error: You and " + friendName + " are already friends.");
        break;
    default:
        ui->message->setText("Add friend failed. Please call technical support.");
        break;
    }
}

void FriendsGUI::refreshFriendList() {

    RocketUser *user = accountController->getUser();
    user->controlFriend()->updateFriendList();

    QStringList friends = user->controlFriend()->getFriendNames();

    QStringListModel *model = new QStringListModel(friends);

    ui->friendList->setModel(model);
}

