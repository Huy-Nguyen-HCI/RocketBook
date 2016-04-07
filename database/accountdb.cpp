#include "accountdb.h"

AccountDB::AccountDB()
{
    accountDB = QSqlDatabase::addDatabase("QSQLITE");
    accountDB.setDatabaseName("../database/accountDB.sqlite");

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

bool AccountDB::addAccount(int accountID, const QString &username, const QString &password, int profileID)
{
    bool success = false;

    if (!username.isEmpty() && !password.isEmpty()) {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO Accounts (AccountID, Username, Password, ProfileID) VALUES (:AccountID, :Username, :Password, :ProfileID)");
        queryAdd.bindValue(":AccountID", accountID);
        queryAdd.bindValue(":Username", username);
        queryAdd.bindValue(":Password", password);
        queryAdd.bindValue(":ProfileID", profileID);

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




bool AccountDB::removeAccount(const QString& username)
{
    bool success = false;

    if (accountExists(username))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM Accounts WHERE Username = (:Username)");
        queryDelete.bindValue(":Username", username);
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
    QSqlQuery queryRetrieve;
    queryRetrieve.prepare("SELECT * FROM Accounts WHERE username = :Username AND Password = :Password");
    queryRetrieve.bindValue(":Username", userName);
    queryRetrieve.bindValue(":Password", password);



    int accountIDIndex = /*query.record().indexOf("AccountID");*/ 0;
    int usernameIndex = /*query.record().indexOf("Username");*/ 1;
    int passwordIndex = /*query.record().indexOf("Password");*/ 2;
    int profileidIndex = /*query.record().indexOf("ProfileID");*/ 3;

    if (queryRetrieve.exec())
    {
        if(queryRetrieve.next())
        {
            accountInfo += queryRetrieve.value(accountIDIndex).toString() + " ";
            accountInfo += queryRetrieve.value(usernameIndex).toString() + " ";
            accountInfo += queryRetrieve.value(passwordIndex).toString() + " ";
            accountInfo += queryRetrieve.value(profileidIndex).toString();
        }
    }
    else
    {
        qDebug() << "account retrieval fails:" <<queryRetrieve.lastError();
    }

    return accountInfo;

}

bool AccountDB::accountExists(const QString& username) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT Username FROM Accounts WHERE Username = (:Username)");
    checkQuery.bindValue(":Username", username);

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
    removeQuery.prepare("DELETE FROM Accounts");

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
