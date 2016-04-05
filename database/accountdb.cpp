#include "accountdb.h"

AccountDB::AccountDB()
{
    accountDB = QSqlDatabase::addDatabase("../accountDB.db");
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
    accountDB = QSqlDatabase::addDatabase(path);
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

bool AccountDB::addaccount(int accountID, const QString &userName, const QString &password, int scrapbookID)
{
    bool success = false;

    if (!userName.isEmpty() && !password.isEmpty()) {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO accounts (accountid, username, password, scrapbookid) VALUES (:accountid, :username, :password, :scrapbookid)");
        queryAdd.bindValue(":accountid", accountID);
        queryAdd.bindValue(":username", userName);
        queryAdd.bindValue(":password", password);
        queryAdd.bindValue(":scrapbookid", scrapbookID);

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




bool AccountDB::removeaccount(const QString& userName)
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

//void AccountDB::printAllAccounts() const
//{
//    qDebug() << "Accounts in db:";
//    QSqlQuery query("SELECT * FROM accounts");
//    while (query.next())
//    {
//        QString name = query.value(idName).toString();
//        qDebug() << "===" << name;
//    }
//}

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

bool AccountDB::removeAllaccounts()
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
