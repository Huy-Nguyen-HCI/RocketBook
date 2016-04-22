#include "messagegui.h"
#include "ui_messagegui.h"

MessageGUI::MessageGUI(AccountController *input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MessageGUI)
{
    ui->setupUi(this);
    accountController = input;
  //  refreshFriendList();
}

MessageGUI::~MessageGUI()
{
    delete ui;
}


void MessageGUI::refreshChats() {




    RocketUser *user = accountController->getUser();
    /**
    user->controlFriend()->updateFriendList();

    QStringList friends = user->controlFriend()->getFriendNames();

    QStringListModel *model = new QStringListModel(friends);

    ui->friendList->setModel(model);
    **/
}


void MessageGUI::refreshFriendList() {

    RocketUser *user = accountController->getUser();
    user->controlFriend()->updateFriendList();

    QStringList friends = user->controlFriend()->getFriendNames();

    QStringListModel *model = new QStringListModel(friends);

    ui->friendList->setModel(model);
}
