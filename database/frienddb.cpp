#include "frienddb.h"

FriendDB::FriendDB()
{
    friendDB = QSqlDatabase::addDatabase("QSQLITE");
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
    friendDB = QSqlDatabase::addDatabase("QSQLITE", "friends");
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
    if (friendDB.isOpen())
    {
        friendDB.close();
    }
}


bool FriendDB::isOpen() const
{
    return friendDB.isOpen();
}

bool FriendDB::addFriend(int accountID, int friendID){

    addFriendBothSides(accountID, friendID);
    return addFriendBothSides(friendID, accountID);

}


bool FriendDB::addFriendBothSides(int accountID, int friendID)
{
    bool success = false;

    QSqlQuery queryAdd;
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
        QSqlQuery queryDelete;
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
QString FriendDB::retrieveFriendsList(int accountId)
{
    QString friendInfo = "";

    qDebug() << "Friends in db:";
    QSqlQuery queryRetrieve;
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

    QSqlQuery checkQuery;
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

    QSqlQuery removeQuery;
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

