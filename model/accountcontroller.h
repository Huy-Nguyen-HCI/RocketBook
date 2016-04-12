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
     * @brief Runs account controller in the terminal. Asks for user input and performs indicated action.
     */
    void run();

    /**
     * @brief Creates new account and adds account information to database.
     * @param username Account username
     * @param password Account password
     * @return true if adding is successful and false otherwise
     */
    bool createNewAccount(QString username, QString password);

    /**
     * @brief Checks of account exists
     * @param username Account username
     * @return true if account exists
     */
    bool checkAccountExists(QString username);

    /**
     * @brief Checks if user entered correct password
     * @param username Account username entered by user
     * @param password Password entered by user
     * @return True if password entered by user matches stored password.
     */
    bool verifyPassword(QString username,QString password);

    /**
     * @brief Sequence of actions for attempting to login into an account.
     */
    void login();

    /**
     * @brief Sequence of actions for attempting to add friend to user database.
     */
    void addFriend();


    void deleteFriend();

    void displayFriends();


private:
    AccountDB* accountDB;
    FriendDB* friendDB;
    std::string askUserName();
    std::string askPassword();



    /**
     * @brief Parses account info and returns only account password
     * @param accountinfo Database row for a given username
     * @return Account's stored password
     */
    QString getPassword(AccountInfoType accountinfo);

    QString getUsername(AccountInfoType accountinfo);

    /**
     * @brief Sequence of actions for attempting to create a new account.
     */
    void createAccount();
    /**
     * @brief Asks for user to select operation
     * @returns Integer value representing user selection
     */
    int requestInput();

};

#endif // ACCOUNTCONTROLLER_H
