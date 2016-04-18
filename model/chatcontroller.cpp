#include "chatcontroller.h"

using namespace std;

ChatController::ChatController()
{
    chatDB = new ChatDB("../database/rocketDB.sqlite");
    messageDB = new MessageDB("../database/rocketDB.sqlite");
    accountDB = new AccountDB("../database/rocketDB.sqlite");
    friendDB = new FriendDB("../database/rocketDB.sqlite");

}

void ChatController::run(){

    if (chatDB->isOpen()){
     //   RocketUser* user= new RocketUser();


        //1----createChat();



        //2-----selectChat();

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

                }
            }
        }

    }
}

void ChatController::createChat(QString username){

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


void ChatController::addMemberToChat(QString username, int chatId){
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
int ChatController::selectChat(QString username){

    if(accountDB->accountExists(username)){


    //Returns all chatId's which the user is in
    std::vector<int>* chatList= chatDB->retrieveChatList(accountDB->retrieveAccountID(username));
    std::vector<int>* accountsInChat;

    //Displays participants in each chat
    for(int i=0; i<chatList->size(); i++){
        accountsInChat=chatDB->retrieveAccountsInChat(chatList->at(i));


        cout << "chat Id: " << chatList->at(i) << endl << "members: ";

        for(int j=0; j<accountsInChat->size(); j++){
            cout << accountDB->getUsername(accountsInChat->at(j)).toStdString() << " ";
        }

        cout << endl;
    }

    int selection=userPicksChat();

    if(selection<chatList->size())
        return chatList->at(selection);
    else
        return -1;



    }


    else{
        cout << "Account entered does not exit" << endl;
    }

}

//Displays all messages in chats and senders
void ChatController::displayMessages(int chatId){

      std::vector<QString>* messageList= messageDB->retrieveChatMessages(chatId);
      std::vector<int>* senderList= messageDB->retrieveChatSenders(chatId);

      for(int i=0;i<messageList->size();i++){
          std::cout << accountDB->getUsername(senderList->at(i)).toStdString() << " : " << messageList->at(i).toStdString() << endl;
      }


}

void ChatController::sendMessage(QString username, int chatId){
    std::string message=userEntersMessage();

    //MessageDB->addMessage(getMax,chatId,accountDB->retrieveAccountID(username), message);
    //Need get max

}



std::string ChatController::askUserName(){
    std::string username;
    std::cout << "Enter user name: ";
    std::cin >> username;
    return username;
}


int ChatController::requestInput(){
    int userInput;
    cout << "\nEnter 0 to quit, 1 to create chat, 2 select chat, 3  \n";
    cin >> userInput;
    return userInput;
}

int ChatController::requestInput2(){
    int userInput;
    cout << "\nEnter 0 to go back, 1 to add account to chat, 2 to display messages, 3 to send message, 4 to remove account from chat \n";
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
    cin >> userInput;
    return userInput;
}
