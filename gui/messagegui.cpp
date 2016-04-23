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
    QModelIndexList selectedFriend = ui->friendList->selectionModel()->selectedIndexes();
    QModelIndexList selectedChat = ui->chatList->selectionModel()->selectedIndexes();


    if (selectedFriend.length() == 0 || selectedChat.length()==0) {
        ui->message->setText("Error: You have to select a friend and a chat to proceed.");
        return;
    }

    // get friend's info
    QString friendName = selectedFriend.at(0).data().toString();
    int chatId = selectedChat.at(0).data().toString().toInt();

    if(accountController->getUser()->getChatController()->addMemberToChat(chatId,friendName)){
        ui->message->setText("Friend added to chat.");

    }

    else
        ui->message->setText("Friend already in chat.");

}



void MessageGUI::on_leaveChat_clicked(){

}

void MessageGUI::on_enterChat_clicked(){

}





void MessageGUI::refreshChats() {


    RocketUser *user = accountController->getUser();

    user->getChatController()->updateChats();

    QStringList chats = user->getChatController()->getChatIdListGUI();

    QStringListModel *model = new QStringListModel(chats);

    ui->chatList->setModel(model);

    ui->chatList->setEditTriggers(QAbstractItemView::NoEditTriggers);

}


void MessageGUI::refreshFriendList() {

    RocketUser *user = accountController->getUser();
    user->controlFriend()->updateFriendList();

    QStringList friends = user->controlFriend()->getFriendNames();

    QStringListModel *model = new QStringListModel(friends);

    ui->friendList->setModel(model);

    ui->friendList->setEditTriggers(QAbstractItemView::NoEditTriggers);

}
