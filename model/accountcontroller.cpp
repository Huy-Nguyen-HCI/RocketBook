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
            else if (userInput == 3)
                addFriend();
            else if(userInput == 4)
                deleteFriend();
            else if(userInput == 5)
                displayFriends();
        }
    }
}

//Doesn't work yet
void AccountController::displayFriends(){
    std::string username=askUserName();
    std::vector<int>* friendlist= friendDB->retrieveAllFriends(accountDB->retrieveAccountID(QString::fromStdString(username)));


    for(unsigned int i=0; i<friendlist->capacity(); i++){
        std::cout << friendlist->at(i) << std::endl;
    }

 //   int userId=accountDB->retrieveAccountID(QString::fromStdString(username));

//    std::cout << friendDB->retrieveAllFriends(userId).toStdString();
                         //^Doesn't work yet

}

void AccountController::addFriend(){
    QString username, friendname;
    int userId, friendId;

    username = QString::fromStdString(askUserName());
    friendname = QString::fromStdString(askUserName());
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

void AccountController::deleteFriend(){
    std::string username, friendname;
    int userId, friendId;

    username=askUserName();
    friendname=askUserName();
    userId=accountDB->retrieveAccountID(QString::fromStdString(username));
    friendId=accountDB->retrieveAccountID(QString::fromStdString(friendname));

    if (!friendDB->friendshipExists(userId,friendId))
        cerr << "Friendship does not exist." << endl;

    else{

     friendDB->removeFriend(userId,friendId);
     std::cout << "You are no longer friends with " << friendname << "." << std::endl;

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

bool AccountController::createNewAccount(QString username, QString password){
    //check what is the last ID of the rocketuser in the database, create the ID for the next user
    int rocketUserID = accountDB->getMaxAccountID() + 1;
    //create a new rocket user with the new ID
    RocketUser* currentUser= new RocketUser(rocketUserID);

    return accountDB->addAccount(currentUser->getID(),username,password,currentUser->getProfile()->getID());
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
    cout << "\nEnter 0 to quit, 1 to create account, 2 to log in, 3 to add friend, 4 to delete friend, 5 to display friends \n";
    cin >> userInput;
    return userInput;
}

