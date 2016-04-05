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

bool AccountDB::addProfile(int profileID, const QString &userName, const QString &password, int scrapbookID)
{
    bool success = false;

    if (!userName.isEmpty() && !password.isEmpty()) {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO profiles (profileid, username, password, scrapbookid) VALUES (:profileid, :username, :password, :scrapbookid)");
        queryAdd.bindValue(":profileid", profileID);
        queryAdd.bindValue(":username", userName);
        queryAdd.bindValue(":password", password);
        queryAdd.bindValue(":scrapbookid", scrapbookID);

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add profile failed: " << queryAdd.lastError();
        }
    }
    return success;
}




bool AccountDB::removeProfile(const QString& userName)
{
    bool success = false;

    if (profileExists(userName))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM profiles WHERE username = (:username)");
        queryDelete.bindValue(":username", userName);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove profile failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove profile failed: profile doesnt exist";
    }

    return success;
}

//void DbManager::printAllPersons() const
//{
//    qDebug() << "Persons in db:";
//    QSqlQuery query("SELECT * FROM people");
//    int idName = query.record().indexOf("name");
//    while (query.next())
//    {
//        QString name = query.value(idName).toString();
//        qDebug() << "===" << name;
//    }
//}

bool AccountDB::profileExists(const QString& userName) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT username FROM profiles WHERE username = (:username)");
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
        qDebug() << "profile exists failed: " << checkQuery.lastError();
    }

    return exists;
}

bool AccountDB::removeAllProfiles()
{
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM profiles");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "remove all profiles failed: " << removeQuery.lastError();
    }

    return success;
}
