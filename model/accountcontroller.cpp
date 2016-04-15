#include "accountcontroller.h"

using namespace std;


AccountController::AccountController()
{
    accountDB = new AccountDB("../database/rocketDB.sqlite");
    friendDB = new FriendDB("../database/rocketDB.sqlite");
}

void AccountController::run(){

    if (accountDB->isOpen()){

        while (true) {
            int userInput=requestInput();

            if (userInput == 0) break;

            else if (userInput == 1) // create account
                createAccount();

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
    }
}

void AccountController::displayFriends(QString username){

    std::vector<int>* friendlist= friendDB->retrieveAllFriends(accountDB->retrieveAccountID(username));


    for(unsigned int i=0; i<friendlist->capacity(); i++){
        std::cout << friendlist->at(i) << std::endl;
    }
}

void AccountController::addFriend(QString username, QString friendname){
    int userId, friendId;

    userId=accountDB->retrieveAccountID(username);
    friendId=accountDB->retrieveAccountID(friendname);

    if (!checkAccountExists(friendname) || !checkAccountExists(username))
        cerr << "Account does not exist." << endl;

    else if(friendDB->friendshipExists(userId,friendId))
        cerr << "You are already friend with " << friendname.toStdString() <<endl;

    else{


     friendDB->addFriend(userId,friendId);

     std::cout << "You are now friends with " << friendname.toStdString() << "!" << std::endl;


    }

}

void AccountController::deleteFriend(QString username, QString friendname){

    int userId, friendId;

    userId=accountDB->retrieveAccountID(username);
    friendId=accountDB->retrieveAccountID(friendname);

    if (!friendDB->friendshipExists(userId,friendId))
        cerr << "Friendship does not exist." << endl;

    else{

     friendDB->removeFriend(userId,friendId);
     std::cout << "You are no longer friends with " << friendname.toStdString() << "." << std::endl;

    }
}

void AccountController::createAccount(){
    QString username, password;
    username = QString::fromStdString(askUserName());
    password = QString::fromStdString(askPassword());

    if (checkAccountExists(username))
        cerr << "Username already exists." << endl;
    else {
        createNewAccount(username,password);
    }

}

void AccountController::login(){
    QString username, password;
    username = QString::fromStdString(askUserName());
    password = QString::fromStdString(askPassword());
    verifyPassword(username,password);

    cout << "id is: " << accountDB->retrieveAccountID(username) << endl;

}

std::string AccountController::askUserName(){
    std::string username;
    std::cout << "Enter user name: ";
    std::cin >> username;
    return username;
}

std::string AccountController::askPassword(){
    std::string password;
    std::cout << "Enter password: ";
    std::cin >> password;
    return password;
}

///Not working right now -> will fix later when stitching rocketuser and accountcontroller
bool AccountController::createNewAccount(QString username, QString password){
    //check what is the last ID of the rocketuser in the database, create the ID for the next user
    int rocketUserID = accountDB->getMaxAccountID() + 1;
    //create a new rocket user with the new ID
    RocketUser* currentUser= new RocketUser(rocketUserID);

    return accountDB->addAccount(currentUser->getID(),username,password,currentUser->getProfile()->getID(), currentUser->isAdmin());
    //cout << "Successfully created account for " << username.toStdString() << endl;

}


QString AccountController::getPassword(AccountInfoType accountinfo){
    return std::get<2>(accountinfo);
}

QString AccountController::getUsername(AccountInfoType accountinfo){
    return std::get<1>(accountinfo);
}

bool AccountController::checkAccountExists(QString username){
    return accountDB->accountExists(username);
}

bool AccountController::verifyPassword(QString username, QString password){

    QString storedPassword = getPassword(accountDB->retrieveAccountInfo(username, password));
    return storedPassword == password;
}

int AccountController::requestInput(){
    int userInput;
    cout << "\nEnter 0 to quit, 1 to create account, 2 to log in, 3 edit friends \n";
    cin >> userInput;
    return userInput;
}

int AccountController::requestInput2(){
    int userInput;
    cout << "\nEnter 0 to go back, 1 add friend, 2 to delete friend, 3 display friend ID's' \n";
    cin >> userInput;
    return userInput;
}

