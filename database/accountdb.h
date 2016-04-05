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
     * @brief AccountDB Construct an account database at
     */
    AccountDB();
    AccountDB(const QString& path);

    ~AccountDB();

    bool isOpen() const;

    bool addProfile(int profileID, const QString& userName, const QString& password, int scrapbookID);

    bool removeProfile(const QString& userName);

    bool profileExists(const QString& userName) const;

    bool addaccount(int accountID, const QString &userName, const QString &password, int profileid);

    bool removeaccount(const QString& userName);

    bool accountExists(const QString& userName) const;

    bool removeAllaccounts();

    bool removeAllProfiles();

private:
    QSqlDatabase accountDB;
};

#endif // ACCOUNTDB_H
