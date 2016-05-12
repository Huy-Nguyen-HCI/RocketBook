#include "friendsgui.h"
#include "ui_friendsgui.h"

FriendsGUI::FriendsGUI(AccountController *input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FriendsGUI)
{
    ui->setupUi(this);
    accountController = input;

    // set up the completer
    QStringList usernames = accountController->getAllUsernames();
    completer = new QCompleter(usernames, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->friendNameInput->setCompleter(completer);
}

FriendsGUI::~FriendsGUI()
{
    delete ui;
    delete completer;
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
    friendProfile->loadPhoto();
}

void FriendsGUI::on_removeFriend_clicked()
{
    // get the selected friend
    QModelIndexList selected = ui->friendList->selectionModel()->selectedIndexes();

    // display error if no friend is selected
    if (selected.length() == 0) {
        ui->message->setText("Error: You have to select a friend to proceed.");
        return;
    }

    // attempt to delete friend and return the status
    QString username = selected.at(0).data().toString();
    FriendController::DeleteFriendStatus status = accountController->getUser()->controlFriend()->deleteFriend(username);

    // display message according to status
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
    // attempt to add friend and return status
    QString friendName = ui->friendNameInput->text();
    FriendController::AddFriendStatus status = accountController->getUser()->controlFriend()->addFriend(friendName);

    // display message according to status
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

    // get the new friend list to display
    RocketUser *user = accountController->getUser();
    user->controlFriend()->updateFriendList();

    // display the friend list
    QStringList friends = user->controlFriend()->getFriendNames();
    QStringListModel *model = new QStringListModel(friends);
    ui->friendList->setModel(model);

    // prevent user from editing friendlist entries in qlist manually
    ui->friendList->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

