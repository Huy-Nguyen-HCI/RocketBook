#ifndef ACCOUNTDB_H
#define ACCOUNTDB_H
#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QDebug>

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
     * Add a new account
     * @param accountID Account ID
     * @param userName
     * @param password
     * @param profileid
     * @return
     */
    bool addAccount(int accountID, const QString &userName, const QString &password, int profileid);

    bool removeAccount(const QString& userName);

    bool accountExists(const QString& userName) const;

    bool removeAllAccounts();

    bool removeAllProfiles();

private:
    QSqlDatabase accountDB;
};

#endif // ACCOUNTDB_H
