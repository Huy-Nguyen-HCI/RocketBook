#include "accountcontroller.h"

using namespace std;


AccountController::AccountController()
{

}

void AccountController::run(){

    accountDB=new AccountDB("../database/rocketDB.sqlite");
   // friendDB=new FriendDB("../database/rocketDB.sqlite");

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
        }
    }
}


void AccountController::addFriend(){
    std::string username, friendname;
    username=askUserName();
   // friendname=askUserName();

    if (!checkAccountExists(friendname) || !checkAccountExists(username))
        cerr << "Account does not exist." << endl;
    else{
     int userId, friendId;
    // accountDB->g


         //friendDB->addFriend()

      //  addFriend();
    //Search through friend Database
    //verify indicated account exists. Check that Friend ID is not already in friend list
    //Add friend if account exists and is not on database

    }

}

void AccountController::createAccount(){
    std::string username, password;
    username=askUserName();
    password=askPassword();

    if (checkAccountExists(username))
        cerr << "Username already exists." << endl;
    else {
        createNewAccount(username,password);
    }

}

void AccountController::login(){
    std::string username, password;
    username=askUserName();
    password=askPassword();
    verifyPassword(username,password);



    cout << "id is: " << accountDB->retrieveAccountId(QString::fromStdString(username)) << endl;

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

void AccountController::createNewAccount(std::string username, std::string password){
//    int rocketUserID =
    RocketUser* currentUser= new RocketUser();
    accountDB->addAccount(currentUser->getID(),QString::fromStdString(username),QString::fromStdString(password),currentUser->getProfile()->getID());
    cout << "Successfully created account for " << username << endl;

}


std::string AccountController::getPassword(std::string accountinfo){
    std::cout << "info is " << accountinfo << std::endl;

    std::string arr[4];
    int i = 0;
    stringstream ssin(accountinfo);
    while (ssin.good() && i < 4){
        ssin >> arr[i];
        ++i;
    }
    std::cout << "password is " << arr[2] << std::endl;
    return arr[2];
}

std::string AccountController::getUserId(std::string accountinfo){
    std::cout << "info is " << accountinfo << std::endl;

    std::string arr[4];
    int i = 0;
    stringstream ssin(accountinfo);
    while (ssin.good() && i < 4){
        ssin >> arr[i];
        ++i;
    }
    std::cout << "user Id is " << arr[3] << std::endl;
    return arr[3];
}

bool AccountController::checkAccountExists(std::string username){
    return accountDB->accountExists(QString::fromStdString(username));
}

void AccountController::verifyPassword(std::string username,std::string password){
    std::string storedPassword=getPassword((accountDB->retrieveAccountInfo(QString::fromStdString(username),QString::fromStdString(password))).toStdString());
    if (storedPassword != password)
        std::cerr << "Wrong username or password" << std::endl;
    else
        std::cout << "Log in successful. Welcome " << username << "!" << std::endl;
}

int AccountController::requestInput(){
    int userInput;
    cout << "\nEnter 0 to quit, 1 to create account, 2 to log in, 3 to add friend \n";
    cin >> userInput;
    return userInput;
}
