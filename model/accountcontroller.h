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
    void createAccount();
    void addFriend();
    std::string getPassword(std::string accountinfo);

private:
    AccountDB* accountDB;
};

#endif // ACCOUNTCONTROLLER_H
