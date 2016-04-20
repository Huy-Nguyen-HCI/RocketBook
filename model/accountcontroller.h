#ifndef ACCOUNTCONTROLLER_H
#define ACCOUNTCONTROLLER_H

#include <iostream>
#include <sstream>
#include <QDebug>
#include <QCoreApplication>
#include "../database/accountdb.h"
#include "../database/frienddb.h"
#include <string>
#include "rocketuser.h"
#include "chatcontroller.h"


/**
 * @brief Account Controller class initiates user actions. This includes Login and Add friend.
 */

class AccountController
{
public:
    /**
     * @brief Constructs and runs account controller.
     */
    AccountController();

    /**
     * @brief Constructs and runs account controller.
     */
    AccountController(QString& path);
//    /**
//     * @brief Runs account controller in the terminal. Asks for user input and performs indicated action.
//     */
//    void run();

    /**
     * @brief Creates new account and adds account information to database.
     * @param username Account username
     * @param password Account password
     * @return true if adding is successful and false otherwise
     */
    bool createNewAccount(QString username,
                          QString password,
                          QString fullName = "",
                          QString photo = "",
                          QString description = "",
                          int adminRights = 0);

    /**
     * @brief Checks of account exists
     * @param username Account username
     * @return true if account exists
     */
    bool checkAccountExists(QString username);



    /**
     * @brief Sequence of actions for attempting to login into an account.
     */
    bool login(QString username, QString password);

    /**
     * @brief Sequence of actions for attempting to add friend to user database.
     */
    void addFriend(QString username, QString friendname);

    void deleteFriend(QString username, QString friendname);

    std::vector<QString> getFriends(QString username);


private:
    AccountDB* accountDB;
    FriendDB* friendDB;
    RocketUser* currentUser;
    QString dbPath;

    /**
     * @brief Checks if user entered correct password
     * @param username Account username entered by user
     * @param password Password entered by user
     * @return True if password entered by user matches stored password.
     */
    bool verifyPassword(QString username,QString password);

    /**
     * @brief Asks for user to select operation
     * @returns Integer value representing user selection
     */
    int requestInput();
    int requestInput2();

    void displayFriends(QString username);

};

#endif // ACCOUNTCONTROLLER_H
