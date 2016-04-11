#include "frienddb.h"

FriendDB::FriendDB()
{
    connectionName.append("friends");
    QSqlDatabase friendDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    friendDB.setDatabaseName("../database/RocketDB.sqlite");

    if (!friendDB.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

FriendDB::FriendDB(const QString &path)
{
    connectionName.append("friends");
    QSqlDatabase friendDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    //Must name database connection

    friendDB.setDatabaseName(path);

    if (!friendDB.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

FriendDB::~FriendDB()
{
    QSqlDatabase::removeDatabase(connectionName);
}


bool FriendDB::isOpen() const
{
    QSqlDatabase friendDB = QSqlDatabase::database(connectionName);
    return friendDB.isOpen();
}

bool FriendDB::addFriend(int accountID, int friendID){

    bool success = false;
    success = addFriendBothSides(accountID, friendID) &&
              addFriendBothSides(friendID, accountID);
    return success;
}


bool FriendDB::addFriendBothSides(int accountID, int friendID)
{
    bool success = false;

    QSqlQuery queryAdd(QSqlDatabase::database(connectionName));
    queryAdd.prepare("INSERT INTO Friends (AccountID, FriendID) VALUES (:AccountID, :FriendID)");
    queryAdd.bindValue(":AccountID", accountID);
    queryAdd.bindValue(":FriendID", friendID);

    if(queryAdd.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "add friend failed: " << queryAdd.lastError();
    }

    return success;
}

bool FriendDB::removeFriend(int accountID, int friendID){

    removeFriendBothSides(accountID, friendID);
    return removeFriendBothSides(friendID, accountID);

}


bool FriendDB::removeFriendBothSides(int accountID, int friendID)
{
    bool success = false;

    if (friendshipExists(accountID, friendID))
    {
        //Deletes friend from user's account's friend list
        QSqlQuery queryDelete(QSqlDatabase::database(connectionName));
        queryDelete.prepare("DELETE FROM Friends WHERE AccountID = (:AccountID) AND FriendID = (:FriendID)");
        queryDelete.bindValue(":AccountID", accountID);
        queryDelete.bindValue(":FriendID", friendID);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove account failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove friend failed: friend does not exist";
    }

    return success;
}

//Doesn't work yet
QString FriendDB::retrieveAllFriends(int accountId)
{
    QString friendInfo = "";

    qDebug() << "Friends in db:";
    QSqlQuery queryRetrieve(QSqlDatabase::database(connectionName));
    queryRetrieve.prepare("SELECT FriendID FROM Friends WHERE AccountID = (:AccountID)");
    queryRetrieve.bindValue(":AccountID", accountId);

    int friendIdIndex = /*query.record().indexOf("FriendID"); */ 0;

    if (queryRetrieve.exec())
    {
        while(queryRetrieve.next())
        {
            friendInfo += queryRetrieve.value(friendIdIndex).toString() + " ";
        }
    }

    else
    {
        qDebug() << "account retrieval fails:" <<queryRetrieve.lastError();
    }

    return friendInfo;

}

bool FriendDB::friendshipExists(int accountID, int friendID) const
{

    bool exists = false;

    QSqlQuery checkQuery(QSqlDatabase::database(connectionName));
    checkQuery.prepare("SELECT AccountID FROM Friends WHERE AccountID = (:AccountID) AND FriendID = (:FriendID)");
    checkQuery.bindValue(":AccountID", accountID);
    checkQuery.bindValue(":FriendID", friendID);

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

bool FriendDB::removeAllFriends()
{
    bool success = false;

    QSqlQuery removeQuery(QSqlDatabase::database(connectionName));
    removeQuery.prepare("DELETE FROM Friends");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "remove all friends failed: " << removeQuery.lastError();
    }

    return success;
}

