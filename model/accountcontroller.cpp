#include "accountcontroller.h"

using namespace std;

QString AccountController::PATH = "/usr11/cs205_2016_Grp08/rocketDB/";  /**< server path */

AccountController::AccountController()
{
    dbPath.append("/usr11/cs205_2016_Grp08/rocketDB/rocketDB.sqlite");
    accountDB = new AccountDB(dbPath);

}

AccountController::AccountController(QString path) {
    dbPath.append(path);
    accountDB = new AccountDB(dbPath);

}

AccountController::~AccountController() {
    delete accountDB;
}

bool AccountController::login(QString username, QString password){
    if (checkAccountExists(username) && verifyPassword(username, password)) {
        AccountInfoType accountInfo = accountDB->retrieveAccountInfo(username);
        int accountID = std::get<0>(accountInfo);
        int profileID = std::get<3>(accountInfo);
        int adminRights = std::get<4>(accountInfo);
        currentUser = new RocketUser(this->dbPath,
                                     accountID,
                                     username,
                                     profileID,
                                     adminRights);
        return true;
    } else {
        return false;
    }
}

void AccountController::logout() {
    RocketUser* tempUser = currentUser;
    currentUser = NULL;
    delete tempUser;
}

RocketUser* AccountController::getUser()
{
    return currentUser;
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

QString AccountController::getPath(){
    return dbPath;
}

int AccountController::getAccountId(QString username){
    return accountDB->retrieveAccountID(username);

}

std::string AccountController::getUserName(int id){
    return accountDB->getUsername(id).toStdString();
}


