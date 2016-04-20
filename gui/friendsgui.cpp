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

}

void FriendsGUI::on_addFriend_clicked()
{
    QString friendName = ui->friendNameInput->text();
    RocketUser::AddFriendStatus status = accountController->getUser()->addFriend(friendName);

    switch (status) {
    case RocketUser::Successful:
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
        ui->message->setText("Add friend failed.");
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

