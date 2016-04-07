#ifndef ACCOUNTCONTROLLER_H
#define ACCOUNTCONTROLLER_H

#include <iostream>
#include <sstream>
#include <QDebug>
#include <QCoreApplication>
#include "../database/accountdb.h"
#include <string>
#include <rocketuser.h>

class AccountController
{
public:
    AccountController();
    void run();
    void addFriend();




private:
    AccountDB* accountDB;
    std::string askUserName();
    std::string askPassword();
    void createNewAccount(std::string username, std::string password);
    bool checkAccountExists(std::string username);

    std::string getPassword(std::string accountinfo);
    bool verifyPassword(std::string username,std::string password);
    void login();
    void createAccount();
    int requestInput();
};

#endif // ACCOUNTCONTROLLER_H
