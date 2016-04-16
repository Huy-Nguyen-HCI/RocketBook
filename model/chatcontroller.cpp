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
        createChat();


        //2-----selectChat();
/**
        while (true) {
            int userInput=requestInput();

            if (userInput == 0) break;

            else if (userInput == 1) // create account


            else if (userInput == 2) // log in
                login();
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
        }
         **/
    }
}

void ChatController::createChat(){
   std::string username;
   username=askUserName();
   if(chatDB->createChat(accountDB->retrieveAccountID(QString::fromStdString(username))))
       cout << "Chat successfully created" << endl;
   else
       cout << "Chat Creation failed";

}


void ChatController::selectChat(){




}



std::string ChatController::askUserName(){
    std::string username;
    std::cout << "Enter user name: ";
    std::cin >> username;
    return username;
}


int ChatController::requestInput(){
    int userInput;
    cout << "\nEnter 0 to quit, 1 to view chats, 2 x, 3 x \n";
    cin >> userInput;
    return userInput;
}
