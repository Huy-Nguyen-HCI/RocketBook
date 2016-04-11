#ifndef ACCOUNTCONTROLLER_H
#define ACCOUNTCONTROLLER_H

#include <iostream>
#include <sstream>
#include <QDebug>
#include <QCoreApplication>
#include "../database/accountdb.h"
#include "../database/frienddb.h"
#include <string>
#include <rocketuser.h>

typedef std::tuple<int, QString, QString, int> AccountInfoType;

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
     * @brief Runs account controller. Asks for user input and performs indicated action.
     */
    void run();
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
     * @brief Creates new account and adds account information to database.
     * @param username Account username
     * @param password Account password
     */
    void createNewAccount(std::string username, std::string password);
    /**
     * @brief Checks of account exists
     * @param username Account username
     * @return true if account exists
     */
    bool checkAccountExists(std::string username);
    /**
     * @brief Parses account info and returns only account password
     * @param accountinfo Database row for a given username
     * @return Account's stored password
     */
    std::string getPassword(AccountInfoType accountinfo);

    std::string getUsername(AccountInfoType accountinfo);
    /**
     * @brief Checks if user entered correct password
     * @param username Account username entered by user
     * @param password Password entered by user
     * @return True if password entered by user matches stored password.
     */
    void verifyPassword(std::string username,std::string password);
    /**
     * @brief Sequence of actions for attempting to login into an account.
     */
    void login();
    /**
     * @brief Sequence of actions for attempting to create a new account.
     */
    void createAccount();
    /**
     * @brief Asks for user to select operation
     * @returns Integer value representing user selection
     */
    int requestInput();

        std::vector<int>* getFriendsList(std::string username);

};

#endif // ACCOUNTCONTROLLER_H
