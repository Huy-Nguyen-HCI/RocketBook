#ifndef ACCOUNTCONTROLLER_H
#define ACCOUNTCONTROLLER_H

#include <iostream>
#include <QDebug>
#include <QCoreApplication>
#include "../database/accountdb.h"
#include <string>
#include <rocketuser.h>

class AccountController
{
public:
    AccountController();


private:
     AccountDB* accountDB;
     void createAccount();
     void addFriend();
     std::string getPassword(std::string accountinfo);
};

#endif // ACCOUNTCONTROLLER_H
