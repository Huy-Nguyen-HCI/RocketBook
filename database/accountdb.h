#ifndef ACCOUNTDB_H
#define ACCOUNTDB_H
#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QDebug>
#include <string>

/**
 * @brief The AccountDB class
 *
 * Create an sqlite3 table in a database file.
 * The database structure:
 * Column 1: accountid INTEGER PRIMARY KEY
 * Column 2: username TEXT
 * Column 3: password TEXT
 * Column 4: profileid INTEGER
 */
class AccountDB
{
public:
    /**
     * @brief AccountDB
     *
     * Construct an account database at ../AccountDB.db
     */
    AccountDB();

    /**
     * @brief AccountDB
     * Construct an account database, given the path
     * @param path path of the account
     */
    AccountDB(const QString& path);

    /**
     * @brief ~AccountDB
     *
     * Default destructor for account
     */
    ~AccountDB();

    /**
     * @brief isOpen
     *
     * Check whether account database is open
     * @return true if yes, false if no
     */
    bool isOpen() const;

    /**
     * @brief addAccount
     * Add a new account to the database table
     *
     * @param accountID Account ID
     * @param userName
     * @param password
     * @param profileid
     * @return true if added, false if not added
     */
    bool addAccount(int accountID, const QString &userName, const QString &password, int profileid);

    /**
     * @brief removeAccount
     * Remove an entire account from the database, knowing the username
     *
     * @param userName the username of the account removed
     * @return true if succeeded, false if failed
     */
    bool removeAccount(const QString& userName);

    /**
     * @brief selectAccount
     * Return a string including details of the account with the username and password
     * @param userName username of the account
     * @param password password of the account
     * @return a string with id, username, password, profileid
     */
    std::string selectAccount(const QString& userName, const QString& password);

    /**
     * @brief accountExists
     * Check if account exists, knowing the username
     *
     * @param userName the username of the account checked
     * @return true if yes, false if no
     */
    bool accountExists(const QString& userName) const;

    /**
     * @brief removeAllAccounts
     * Remove all accounts existed in the database
     * @return true if succeeded, false if failed
     */
    bool removeAllAccounts();


private:
    QSqlDatabase accountDB;
};

#endif // ACCOUNTDB_H
