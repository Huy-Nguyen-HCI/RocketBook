#include "chatcontroller.h"

using namespace std;

ChatController::ChatController(QString dbPath, int accountId)
{
    this->accountId=accountId;
    chatDB = new ChatDB(dbPath);
    messageDB = new MessageDB(dbPath);
    accountDB = new AccountDB(dbPath);
    username=accountDB->getUsername(accountId);

}

ChatController::~ChatController()
{
    delete accountDB;
    delete chatDB;
    delete messageDB;
}

//updates user's chat list
void ChatController::updateChats(){

    chatList.empty();
    Chat* temp;

    int chatId;
    std::vector<int>* chats= getChatIdList();
    std::vector<int>* members;
    for(unsigned int i=0;i<chats->size();i++){
        chatId=chats->at(i);
        members= chatDB->retrieveAccountsInChat(chats->at(i));


        temp= new Chat(chatId,members);

        chatList.push_back(temp);
    }
}

void ChatController::createChat(QString friendName){

    if(accountDB->accountExists(username) && accountDB->accountExists(friendName)){

        if(chatDB->createChat(accountDB->retrieveAccountID(username))){
            chatDB->addToChat(chatDB->getMaxChatID(),accountDB->retrieveAccountID(friendName));
            updateChats();
        }
    }
}

bool ChatController::addMemberToChat(int chatId,QString friendName){

    if(chatDB->addToChat(chatId, accountDB->retrieveAccountID(friendName))){
        return true;
    }
    else
        cout << friendName.toStdString() << " was not added to chat" << endl;
    return false;
}

bool ChatController::removeUserFromChat(int chatId, QString username){

    if(chatDB->inChat(chatId,accountDB->retrieveAccountID(username))){
        chatDB->removeFromChat(chatId,accountDB->retrieveAccountID(username));
        updateChats();
        return true;
    }
    return false;
}

QStringList ChatController::getChatIdListGUI(){
    QStringList list;
    std::vector<int>* chatIds=getChatIdList();


    for(unsigned int i=0;i<chatIds->size();i++)
        list.append(QString::number(chatIds->at(i)));
    return list;
}

//deletes chats with only one member
void ChatController::cleanUp(){
    for(unsigned int i=0;i<=chatDB->getMaxChatID();i++){
        if(chatDB->retrieveAccountsInChat(i)->size()==1)
            chatDB->removeFromChat(i,accountId);
    }
}

QStringList ChatController::getMessageListGUI(int chatId){
    std::vector<QString>* messages= messageDB->retrieveChatMessages(chatId);
    std::vector<int>* senders= messageDB->retrieveChatSenders(chatId);
    QStringList list;

    std::string message;
    for(int i=messages->size()-1;i>=0;i--){
        message=accountDB->getUsername(senders->at(i)).toStdString() + " : " + messages->at(i).toStdString();
        list.append(QString::fromStdString(message));
    }
    return list;
}

QStringList ChatController::getChatMembersGUI(int chatId){
    std::vector<int>*  members=chatDB->retrieveAccountsInChat(chatId);
    QStringList list;

    for(unsigned int i=0;i<members->size();i++)
        list.append(accountDB->getUsername(members->at(i)));
    return list;
}

bool ChatController::sendMessage(int chatId, QString message){

    if(messageDB->addMessage(messageDB->getMaxMessageID(chatId)+1,chatId,accountDB->retrieveAccountID(username), message))
        return true;
    return false;

}

std::vector<int>* ChatController::getChatIdList(){
    return chatDB->retrieveChatList(accountDB->retrieveAccountID(username));
}


std::vector<int>* ChatController::getSenderList(int chatId){
    return messageDB->retrieveChatSenders(chatId);
}

std::vector<QString>* ChatController::getMessageList(int chatId){
    return messageDB->retrieveChatMessages(chatId);
}
