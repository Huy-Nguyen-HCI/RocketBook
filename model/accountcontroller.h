#ifndef ACCOUNTCONTROLLER_H
#define ACCOUNTCONTROLLER_H

#include <iostream>
#include <sstream>
#include <qdebug.h>
#include <QCoreApplication>
#include "../database/accountdb.h"
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
    AccountController(QString path);

    ~AccountController();

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
     * @brief login
     * Sequence of actions for attempting to login into an account.
     * @param username The username of the account
     * @param password The password of the account
     * @return true if login passes, false if login fails.
     */
    bool login(QString username, QString password);

    /**
     * @brief logout
     * Sequence of actions to log out of an account
     * @return true of log out passes, false if it fails
     */
    void logout();

    /**
     * @brief Returns the user associated with the account
     */
    RocketUser *getUser();

    QString getPath();

    int getAccountId(QString username);

    std::string getUserName(int id);

    static QString PATH;

    QStringList getAllUsernames() { return accountDB->getAllUsernames(); }

private:
    AccountDB* accountDB;
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



};

#endif // ACCOUNTCONTROLLER_H
