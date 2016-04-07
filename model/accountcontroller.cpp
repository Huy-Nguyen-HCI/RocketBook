#include "accountcontroller.h"

using namespace std;


AccountController::AccountController()
{

}

void AccountController::run(){

    accountDB=new AccountDB("../database/accountDB.sqlite");
        std::string username, password;
    if (accountDB->isOpen()){

        while (true) {
            int userInput=requestInput();

            if (userInput == 0) break;

            else if (userInput == 1) // create account
                createAccount();

            else if (userInput == 2)              // log in
                login();
        }
    }
}


void AccountController::addFriend(){




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
}

std::string AccountController::askUserName(){
    std::string username;
    std::cout << "Enter user name: ";
    std::cin >> username;
    return username;
}

std::string AccountController::askPassword(){
    std::string password;
    std::cout << "Enter user name: ";
    std::cin >> password;
    return password;
}

void AccountController::createNewAccount(std::string username, std::string password){
    RocketUser* currentUser= new RocketUser();
    accountDB->addAccount(currentUser->getPlayerId(),QString::fromStdString(username),QString::fromStdString(password),currentUser->getProfile()->getID());
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


bool AccountController::checkAccountExists(std::string username){
    return accountDB->accountExists(QString::fromStdString(username));
}

bool AccountController::verifyPassword(std::string username,std::string password){
    std::string storedPassword=getPassword((accountDB->retrieveAccountInfo(QString::fromStdString(username),QString::fromStdString(password))).toStdString());
    if (storedPassword != password)
        std::cerr << "Wrong username or password" << std::endl;
    else
        std::cout << "Log in successful. Welcome " << username << "!" << std::endl;
}

int AccountController::requestInput(){
    int userInput;
    cout << "\nEnter 0 to quit, 1 to create account, 2 to log in \n";
    cin >> userInput;
    return userInput;
}
