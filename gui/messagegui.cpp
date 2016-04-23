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

void MessageGUI::on_createChat_clicked(){
    accountController->getUser()->getChatController()->createChat();
}


void MessageGUI::on_addToChat_clicked(){

}



void MessageGUI::on_leaveChat_clicked(){

}

void MessageGUI::on_enterChat_clicked(){

}





void MessageGUI::refreshChats() {


    RocketUser *user = accountController->getUser();

    user->getChatController()->updateChats();

  //  QStringList chats = user->getChatController()->getChatIdListGUI();

  //  QStringListModel *model = new QStringListModel(chats);

   // ui->chatList->setModel(model);

}


void MessageGUI::refreshFriendList() {

    RocketUser *user = accountController->getUser();
    user->controlFriend()->updateFriendList();

    QStringList friends = user->controlFriend()->getFriendNames();

    QStringListModel *model = new QStringListModel(friends);

    ui->friendList->setModel(model);
}
