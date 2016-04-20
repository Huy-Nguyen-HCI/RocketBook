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

}

void FriendsGUI::on_removeFriend_clicked()
{
    QModelIndexList selected = ui->friendList->selectionModel()->selectedIndexes();
    if (selected.length() == 0) {
        ui->message->setText("Error: You have to select a friend to proceed.");
        return;
    }

    QString username = selected.at(0).data().toString();
    RocketUser::DeleteFriendStatus status = accountController->getUser()->deleteFriend(username);

    switch (status) {
    case RocketUser::DeleteSuccessful:
        ui->message->setText("You and " + username + " are no longer friends.");
        refreshFriendList();
        break;
    case RocketUser::FriendshipNotExist:
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
    RocketUser::AddFriendStatus status = accountController->getUser()->addFriend(friendName);

    switch (status) {
    case RocketUser::AddSuccessful:
        ui->message->setText("Add friend successful!");
        refreshFriendList();
        break;

    case RocketUser::FriendNotExist:
        ui->message->setText("Error: Input username does not exist.");
        break;

    case RocketUser::AlreadyFriend:
        ui->message->setText("Error: You and " + friendName + " are already friends.");
        break;
    default:
        ui->message->setText("Add friend failed. Please call technical support.");
        break;
    }
}

void FriendsGUI::refreshFriendList() {

    RocketUser *user = accountController->getUser();
    user->updateFriendList();

    QStringList friends = user->getFriendNames();

    QStringListModel *model = new QStringListModel(friends);

    ui->friendList->setModel(model);
}

