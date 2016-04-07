#include "frienddb.h"

FriendDB::FriendDB()
{
    friendDB = QSqlDatabase::addDatabase("QSQLITE");
    friendDB.setDatabaseName("../database/accountDB.sqlite");

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
    friendDB = QSqlDatabase::addDatabase("QSQLITE");
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

bool FriendDB::addFriend(int accountID, int friendID)
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




bool FriendDB::removeFriend(int accountID, int friendID)
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

        //Deletes user from friend's account's friend list
        QSqlQuery queryDelete2;
        queryDelete2.prepare("DELETE FROM Friends WHERE AccountID = (:AccountID) AND FriendID = (:FriendID)");
        queryDelete2.bindValue(":AccountID", friendID);
        queryDelete2.bindValue(":FriendID", accountID);
        success = queryDelete2.exec();

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

QString FriendDB::retrieveFriendsList(int accountId)
{
    QString friendInfo = "";

    qDebug() << "Friends in db:";
    QSqlQuery queryRetrieve;
    queryRetrieve.prepare("SELECT * FROM Accounts WHERE AccuntID = (:AccountID)");
    queryRetrieve.bindValue(":AccountID", accountId);



    int accountIdIndex = /*query.record().indexOf("AccountID");*/ 0;
    int friendIdIndex = /*query.record().indexOf("FriendID"); */ 2;

    if (queryRetrieve.exec())
    {
        while(queryRetrieve.next())
        {
            friendInfo += queryRetrieve.value(accountIdIndex).toString() + " ";
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
    checkQuery.prepare("SELECT Username FROM Accounts WHERE AccountID = (:AccountID) AND FriendID = (:FriendID)");
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
    removeQuery.prepare("DELETE FROM friends");

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

