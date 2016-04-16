#include "chatcontroller.h"

using namespace std;

ChatController::ChatController()
{
    chatDB = new ChatDB("../database/rocketDB.sqlite");
    messageDB = new MessageDB("../database/rocketDB.sqlite");
    accountDB = new AccountDB("../database/rocketDB.sqlite");

}

void ChatController::run(){

    if (chatDB->isOpen()){
     //   RocketUser* user= new RocketUser();


        //1----createChat();



        //2-----selectChat();

        while (true) {
            int userInput=requestInput();

            if (userInput == 0) break;

            else if (userInput == 1) // create account
                createChat();

            else if (userInput == 2) // log in
                selectChat();
            /**
            else if (userInput == 3){
                int input2=requestInput2();


                if (input2==0) break;
                else if(input2==1){
                    std::string username=askUserName();
                    std::string friendname=askUserName();
                    addFriend(QString::fromStdString(username), QString::fromStdString(friendname));
                }
                else if(input2 == 2){
                    std::string username=askUserName();
                    std::string friendname=askUserName();
                    deleteFriend(QString::fromStdString(username), QString::fromStdString(friendname));

                }
                else if(input2 == 3){
                    std::string username=askUserName();
                    displayFriends(QString::fromStdString(username));

                }
            }
            **/
        }

    }
}

void ChatController::createChat(){
    QString username;
    username=QString::fromStdString(askUserName());
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


void ChatController::selectChat(){

    QString username;
    username=QString::fromStdString(askUserName());
    if(accountDB->accountExists(username)){


    //Returns all chatId's which the user is in
    std::vector<int>* chatList= chatDB->retrieveChatList(accountDB->retrieveAccountID(username));
    std::vector<int>* accountsInChat;

    //Displas participants in each chat
    for(int i=0; i<chatList->size(); i++){
        accountsInChat=chatDB->retrieveAccountsInChat(chatList->at(i));



        cout << "chat Id: " << chatList->at(i) << endl << "members: ";
        /**
        for(int j=0; i<accountsInChat->size(); j++){
            cout << accountDB->getUsername(accountsInChat->at(j)).toStdString() << " ";
        }

        **/
        cout << endl;
    }


    }


    else{
        cout << "Account entered does not exit" << endl;
    }

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
