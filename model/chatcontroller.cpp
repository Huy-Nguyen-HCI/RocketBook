#include "chatcontroller.h"

using namespace std;

ChatController::ChatController(QString dbPath, int accountId)
{
    this->accountId=accountId;
    chatDB = new ChatDB(dbPath);
    messageDB = new MessageDB(dbPath);
    accountDB = new AccountDB(dbPath);
    username=accountDB->getUsername(accountId);
  //  std::vector<Chat*>* chatList= new ;

}

ChatController::~ChatController()
{
    delete accountDB;
    delete chatDB;
    delete messageDB;
}

//updates user's chat list
void ChatController::updateChats(){

   // cleanUp();
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
               //^This line breaks code currently
    }
}

void ChatController::createChat(QString friendName){

    if(accountDB->accountExists(username) && accountDB->accountExists(friendName)){

    if(chatDB->createChat(accountDB->retrieveAccountID(username))){
           cout << "Chat successfully created" << endl;
           chatDB->addToChat(chatDB->getMaxChatID(),accountDB->retrieveAccountID(friendName));
     updateChats();
    }
       else
           cout << "Chat Creation failed" << endl;

    }
    else{
        cout << "Account entered does not exit" << endl;
    }

}

bool ChatController::addMemberToChat(int chatId,QString friendName){

    if(chatDB->addToChat(chatId, accountDB->retrieveAccountID(friendName))){
        cout << friendName.toStdString() << " successfully added to chat" << endl;
        return true;
    }
    else
        cout << friendName.toStdString() << " was not added to chat" << endl;
    return false;
}

bool ChatController::removeUserFromChat(int chatId, QString username){

    if(chatDB->inChat(chatId,accountDB->retrieveAccountID(username))){
        chatDB->removeFromChat(chatId,accountDB->retrieveAccountID(username));
        cout << username.toStdString() << " has been deleted from chat";
        updateChats();
        return true;
    }
    else
        cout <<username.toStdString() << " is not in chat";
    return false;
}

QStringList ChatController::getChatIdListGUI(){
    QStringList list;
    std::vector<int>* chatIds=getChatIdList();


    for(unsigned int i=0;i<chatIds->size();i++)
    list.append(QString::number(chatIds->at(i)));
    return list;
}
/**
QStringList ChatController::getChatIdListGUI(){
    QStringList list;
    std::vector<int>* chatIds=getChatIdList();


    for(unsigned int i=0;i<chatIds->size();i++)
    list.append(QString::number(chatIds->at(i)));
    return list;
}
**/

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















/**
//Displays all chats and asks user to pick one. User can pick from first chat
//by entering 0 or last chat by entering # of chats-1
int ChatController::selectChat(){

    if(accountDB->accountExists(username)){


        //Returns all chatId's which the user is in
        std::vector<int>* chatList= chatDB->retrieveChatList(accountDB->retrieveAccountID(username));
        std::vector<int>* accountsInChat;

        //Displays participants in each chat
        for(unsigned int i=0; i<chatList->size(); i++){
            accountsInChat=chatDB->retrieveAccountsInChat(chatList->at(i));


            cout << "chat Id: " << chatList->at(i) << endl << "members: ";

            for(unsigned int j=0; j<accountsInChat->size(); j++){
                cout << accountDB->getUsername(accountsInChat->at(j)).toStdString() << " ";
            }

            cout << endl;
        }
model
        int selection=userPicksChat();

        if(selection<chatList->capacity())
            return chatList->at(selection);
        else{
            cout << "selection failed";
            return -1;
        }


    }


    else{
        cout << "Account entered does not exit" << endl;
    }

}
**/


/**
//Displays all messages in chats and senders
void ChatController::displayMessages(int chatId){

    std::vector<QString>* messageList= messageDB->retrieveChatMessages(chatId);
      std::vector<int>* senderList= messageDB->retrieveChatSenders(chatId);

      for(int i=0;i<messageList->size();i++){
          std::cout << accountDB->getUsername(senderList->at(i)).toStdString() << ": " << messageList->at(i).toStdString() << endl;
      }


}
**/

/**
//User enters message and message is added to message database for the chat specified
void ChatController::sendMessage(int chatId){
    std::string message=userEntersMessage();

    if(messageDB->addMessage(messageDB->getMaxMessageID(chatId)+1,chatId,accountDB->retrieveAccountID(username), QString::fromStdString(message)))
        cout << "Message Sent" << endl;

    else
        cout << "send message failed" << endl;

}
**/

//User enters Message ID here. In real program, message ID must be stored in chat object
void ChatController::deleteMessage(int chatId){
    int userInput;
    cout << "\n message number to delete \n";
    cin >> userInput;
    if(messageDB->deleteMessage(chatId,userInput))
        cout << "Message successfully deleted" << endl;
    else
        cout << "Message deletion failed" << endl;

}

std::vector<int>* ChatController::getChatIdList(){
    return chatDB->retrieveChatList(accountDB->retrieveAccountID(username));
}


/**
QStringList ChatController::getChatIdListUI(){

    QStringList list;

    for(unsigned int i=0;i<chatList.size();i++){
    list.append(QString::fromStdString(std::to_string(chatList.at(i)->getChatId())));
    }
}
**/

std::vector<int>* ChatController::getSenderList(int chatId){
    return messageDB->retrieveChatSenders(chatId);
}

//QStringList* ChatController::getSenderListGUI(int chatId){
    /**
    std::vector<int>* senders= messageDB->retrieveChatSenders(chatId);

    for(unsigned int i=0;i<senders->size();i++)
    list.append(QString::number(chatIds->at(i)));
    return list;
    **/

//}

std::vector<QString>* ChatController::getMessageList(int chatId){
    return messageDB->retrieveChatMessages(chatId);
}





/**
std::string ChatController::askUserName(){
    std::string username;
    std::cout << "Enter user name: ";
    std::cin >> username;
    return username;
}


int ChatController::requestInput(){
    int userInput;
    cout << "\nEnter 0 to quit, 1 to create chat, 2 select chat \n";
    cin >> userInput;
    return userInput;
}

int ChatController::requestInput2(){
    int userInput;
    cout << "\nEnter 0 to go back, 1 to add account to chat, 2 to display messages, 3 to send message, 4 to remove account from chat, 5 to delete message \n";
    cin >> userInput;
    return userInput;
}


int ChatController::userPicksChat(){
    int userInput;
    cout << "\n Enter number of chat you would like (not chat id) \n";
    cin >> userInput;
    return userInput;
}

string ChatController::userEntersMessage(){
    string userInput;
    cout << "\n Enter message \n";
    std::cin.ignore();
    getline(cin, userInput);
    return userInput;
}
**/
