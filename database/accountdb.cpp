#include "accountdb.h"

AccountDB::AccountDB()
{
    accountDB = QSqlDatabase::addDatabase("QSQLITE");
    accountDB.setDatabaseName("../accountDB.db");

    if (!accountDB.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

AccountDB::AccountDB(const QString &path)
{
    accountDB = QSqlDatabase::addDatabase("QSQLITE");
    accountDB.setDatabaseName(path);

    if (!accountDB.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

AccountDB::~AccountDB()
{
    if (accountDB.isOpen())
    {
        accountDB.close();
    }
}

bool AccountDB::isOpen() const
{
    return accountDB.isOpen();
}

bool AccountDB::addAccount(int accountID, const QString &userName, const QString &password, int profileid)
{
    bool success = false;

    if (!userName.isEmpty() && !password.isEmpty()) {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO accounts (accountid, username, password, profileid) VALUES (:accountid, :username, :password, :profileid)");
        queryAdd.bindValue(":accountid", accountID);
        queryAdd.bindValue(":username", userName);
        queryAdd.bindValue(":password", password);
        queryAdd.bindValue(":profileid", profileid);

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add account failed: " << queryAdd.lastError();
        }
    }
    return success;
}




bool AccountDB::removeAccount(const QString& userName)
{
    bool success = false;

    if (accountExists(userName))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM accounts WHERE username = (:username)");
        queryDelete.bindValue(":username", userName);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove account failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove account failed: account doesnt exist";
    }

    return success;
}

QString AccountDB::retrieveAccountInfo(const QString& userName, const QString& password)
{
    QString accountInfo = "";

    qDebug() << "Accounts in db:";
    QSqlQuery query("SELECT * FROM accounts WHERE username = (:username) AND password = (:password)");
    query.bindValue(":username", userName);
    query.bindValue(":password", password);

    int accountidIndex = query.record().indexOf("username");
    int usernameIndex = query.record().indexOf("username");
    int passwordIndex = query.record().indexOf("password");
    int profileidIndex = query.record().indexOf("profileid");

    if (query.exec())
    {
        if(query.next())
        {
            accountInfo += query.value(accountidIndex).toString() + " ";
            accountInfo += query.value(usernameIndex).toString() + " ";
            accountInfo += query.value(passwordIndex).toString() + " ";
            accountInfo += query.value(profileidIndex).toString();
        }
    }
    else
    {
        qDebug() << "account retrieval fails:" <<query.lastError();
    }

    return accountInfo;

}

bool AccountDB::accountExists(const QString& userName) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT username FROM accounts WHERE username = (:username)");
    checkQuery.bindValue(":username", userName);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "account exists failed: " << checkQuery.lastError();
    }

    return exists;
}

bool AccountDB::removeAllAccounts()
{
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM accounts");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "remove all accounts failed: " << removeQuery.lastError();
    }

    return success;
}
