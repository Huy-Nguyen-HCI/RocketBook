#include "accountcontroller.h"

using namespace std;


AccountController::AccountController()
{
    dbPath.append("../database/rocketDB.sqlite");
    accountDB = new AccountDB(dbPath);

}

AccountController::AccountController(QString &path) {
    dbPath.append(path);
    accountDB = new AccountDB(dbPath);

}

//void AccountController::run(){

//    if (accountDB->isOpen()){

//        while (true) {
//            int userInput=requestInput();

//            if (userInput == 0) break;

//            else if (userInput == 1) // create account
//                createAccount();

//            else if (userInput == 2) // log in
//                login();
//            else if (userInput == 3){
//                int input2=requestInput2();


//                if (input2==0) break;
//                else if(input2==1){
//                    std::string username=askUserName();
//                    std::string friendname=askUserName();
//                    addFriend(QString::fromStdString(username), QString::fromStdString(friendname));
//                }
//                else if(input2 == 2){
//                    std::string username=askUserName();
//                    std::string friendname=askUserName();
//                    deleteFriend(QString::fromStdString(username), QString::fromStdString(friendname));

//                }
//                else if(input2 == 3){
//                    std::string username=askUserName();
//                    displayFriends(QString::fromStdString(username));

//                }
//            }
//            else if(userInput==4){
//                ChatController b;
//                b.run();
//                accountDB = new AccountDB("../database/rocketDB.sqlite");
//            }
//        }
//    }
//}


bool AccountController::login(QString username, QString password){
    if (checkAccountExists(username) && verifyPassword(username, password)) {
        AccountInfoType accountInfo = accountDB->retrieveAccountInfo(username);
        int accountID = std::get<0>(accountInfo);
        int profileID = std::get<3>(accountInfo);
        int adminRights = std::get<4>(accountInfo);
        currentUser = new RocketUser(dbPath, accountID, username, profileID, adminRights);
        return true;
    } else {
        return false;
    }
}

RocketUser AccountController::getUser()
{
    return *currentUser;
}

bool AccountController::createNewAccount(QString username,
                                         QString password,
                                         QString fullName,
                                         QString photo,
                                         QString description,
                                         int adminRights){
    //check what is the last ID of the rocketuser in the database, create the ID for the next user
    int rocketUserID = accountDB->getMaxAccountID() + 1;
    //create a new rocket user with the new ID
    currentUser= new RocketUser(dbPath,
                                rocketUserID,
                                username,
                                fullName,
                                photo,
                                description,
                                adminRights);

    //if add account to database is successful
    return accountDB->addAccount(currentUser->getID(),
                                 username,
                                 password,
                                 currentUser->getProfile()->getID(),
                                 adminRights);
}


bool AccountController::checkAccountExists(QString username){
    return accountDB->accountExists(username);
}

bool AccountController::verifyPassword(QString username, QString password){

    AccountInfoType accountInfo = accountDB->retrieveAccountInfo(username);
    QString storedPassword = std::get<2>(accountInfo);
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


