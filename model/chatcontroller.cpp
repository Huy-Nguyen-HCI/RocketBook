#include "chatcontroller.h"

using namespace std;

ChatController::ChatController(QString dbPath, int accountId)
{
    this->accountId=accountId;
    chatDB = new ChatDB(dbPath);
    messageDB = new MessageDB(dbPath);
    accountDB = new AccountDB(dbPath);
    friendDB = new FriendDB(dbPath);

}
/**
void ChatController::run(){

    if (chatDB->isOpen()){

        QString username=QString::fromStdString(askUserName());

        while (true) {

            int userInput=requestInput();

            if (userInput == 0) break;

            else if (userInput == 1) // create chat
                createChat(username);

            else if (userInput == 2){ // select chat
                int chatSelection=selectChat(username);
                if(chatSelection!=-1){


                    int input2=requestInput2();


                    if (input2==0) break;

                    else if(input2==1){ //Add member to chat
                        addMemberToChat(username, chatSelection);
                    }



                    else if(input2 == 2){ //Display messages
                        displayMessages(chatSelection);
                    }

                    else if(input2 == 3){ //Send message in chat
                        sendMessage(username, chatSelection);
                    }
                    else if(input2 == 4){ //Remove someone from a chat
                        removeUserFromChat(chatSelection);
                    }
                    else if(input2 == 5){ //Delete message
                        deleteMessage(chatSelection);
                    }
                }
            }
        }

    }
}
**/
void ChatController::createChat(){

    if(accountDB->accountExists(username)){


    if(chatDB->createChat(accountDB->retrieveAccountID(username)))
           cout << "Chat successfully created" << endl;
       else
           cout << "Chat Creation failed" << endl;

    }
    else{
        cout << "Account entered does not exit" << endl;
    }

}


void ChatController::addMemberToChat(int chatId){
    QString friendname;
    friendname=QString::fromStdString(askUserName());
    //Checks if users exist and that they are friends
    if(friendDB->friendshipExists(accountDB->retrieveAccountID(username),accountDB->retrieveAccountID(friendname))){


        if(chatDB->addToChat(chatId, accountDB->retrieveAccountID(friendname)))
            cout << friendname.toStdString() << " successfully added to chat" << endl;
        else
            cout << "Chat Creation failed" << endl;

    }
    else{
        cout << "Accounts are not friends and thus cannot be added to chat" << endl;

    }

}

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

        int selection=userPicksChat();

        if(selection<chatList->size())
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

void ChatController::removeUserFromChat(int chatId){
    QString nameToDelete=QString::fromStdString(askUserName());

    if(chatDB->inChat(chatId,accountDB->retrieveAccountID(nameToDelete))){
        chatDB->removeFromChat(chatId,accountDB->retrieveAccountID(nameToDelete));
        cout << nameToDelete.toStdString() << " has been deleted from chat";

    }
    else
        cout << nameToDelete.toStdString() << " is not in chat";

}


//Displays all messages in chats and senders
void ChatController::displayMessages(int chatId){

    std::vector<QString>* messageList= messageDB->retrieveChatMessages(chatId);
      std::vector<int>* senderList= messageDB->retrieveChatSenders(chatId);

      for(int i=0;i<messageList->size();i++){
          std::cout << accountDB->getUsername(senderList->at(i)).toStdString() << ": " << messageList->at(i).toStdString() << endl;
      }


}

//User enters message and message is added to message database for the chat specified
void ChatController::sendMessage(int chatId){
    std::string message=userEntersMessage();

    if(messageDB->addMessage(messageDB->getMaxMessageID(chatId)+1,chatId,accountDB->retrieveAccountID(username), QString::fromStdString(message)))
        cout << "Message Sent" << endl;

    else
        cout << "send message failed" << endl;

}

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

std::vector<int>* ChatController::getSenderList(int chatId){
    return messageDB->retrieveChatSenders(chatId);
}

std::vector<QString>* ChatController::getMessageList(int chatId){
    return messageDB->retrieveChatMessages(chatId);
}


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
