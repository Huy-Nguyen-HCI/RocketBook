#include "accountcontroller.h"

using namespace std;


AccountController::AccountController()
{

}

void AccountController::run(){

    accountDB=new AccountDB("../database/rocketDB.sqlite");
    friendDB=new FriendDB("../database/rocketDB.sqlite");

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
        }
    }
}


void AccountController::addFriend(){
    std::string username, friendname;
    username=askUserName();
    friendname=askUserName();

    if (!checkAccountExists(friendname) || !checkAccountExists(username))
        cerr << "Account does not exist." << endl;

    //also must check if users are friends^^^^^^^^^^^^^^^^^^^^^

    else{
     int userId, friendId;
     userId=accountDB->retrieveAccountId(QString::fromStdString(username));
     friendId=accountDB->retrieveAccountId(QString::fromStdString(friendname));

     friendDB->addFriend(userId,friendId);

     std::cout << "You are now friends with " << friendname << "!" << std::endl;


    }

}

void AccountController::deleteFriend(){
    std::string username, friendname;
    int userId, friendId;

    username=askUserName();
    friendname=askUserName();
    userId=accountDB->retrieveAccountId(QString::fromStdString(username));
    friendId=accountDB->retrieveAccountId(QString::fromStdString(friendname));

    //Check if friendship exists



    if (!friendDB->friendshipExists(userId,friendId))
        cerr << "Friendship does not exist." << endl;

    else{



     friendDB->removeFriend(userId,friendId);
     std::cout << "You are no longer friends with " << friendname << "." << std::endl;

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
    //check what is the last ID of the rocketuser in the database, create the ID for the next user
    int rocketUserID = accountDB->getMaxAccountID() + 1;
    //create a new rocket user with the new ID
    RocketUser* currentUser= new RocketUser(rocketUserID);

    accountDB->addAccount(currentUser->getID(),QString::fromStdString(username),QString::fromStdString(password),currentUser->getProfile()->getID());
    cout << "Successfully created account for " << username << endl;

}


std::string AccountController::getPassword(AccountInfoType accountinfo){
    return std::get<2>(accountinfo).toStdString();
}

std::string AccountController::getUsername(AccountInfoType accountinfo){
    return std::get<1>(accountinfo).toStdString();
}

bool AccountController::checkAccountExists(std::string username){
    return accountDB->accountExists(QString::fromStdString(username));
}

void AccountController::verifyPassword(std::string username,std::string password){
    const QString user = QString::fromStdString(username);
    const QString pass = QString::fromStdString(password);
    std::string storedPassword = getPassword(accountDB->retrieveAccountInfo(user, pass));
    if (storedPassword != password)
        std::cerr << "Wrong username or password" << std::endl;
    else
        std::cout << "Log in successful. Welcome " << username << "!" << std::endl;
}

int AccountController::requestInput(){
    int userInput;
    cout << "\nEnter 0 to quit, 1 to create account, 2 to log in, 3 to add friend, 4 to delete friend \n";
    cin >> userInput;
    return userInput;
}
