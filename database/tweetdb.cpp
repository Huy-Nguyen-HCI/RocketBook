#include "tweetdb.h"

TweetDB::TweetDB()
{
    tweetDB = QSqlDatabase::addDatabase("QSQLITE");
    tweetDB.setDatabaseName("TweetDB.sqlite");

    if (!tweetDB.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

TweetDB::TweetDB(const QString &path)
{
    tweetDB = QSqlDatabase::addDatabase("QSQLITE");
    tweetDB.setDatabaseName(path);

    if (!tweetDB.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

TweetDB::~TweetDB()
{
    if (tweetDB.isOpen())
    {
        tweetDB.close();
    }
}

bool TweetDB::isOpen() const
{
    return tweetDB.isOpen();
}

bool TweetDB::addTweet(int tweetID, int scrapbookID, const QString &tweetContent)
{
    bool success = false;

    QSqlQuery queryAdd;
    queryAdd.prepare("INSERT INTO Tweets (TweetID, ScrapbookID, TweetContent) VALUES (:TweetID, :ScrapbookID, :TweetContent)");
    queryAdd.bindValue(":TweetID", tweetID);
    queryAdd.bindValue(":ScrapbookID", scrapbookID);
    queryAdd.bindValue(":TweetContent", tweetContent);

    if(queryAdd.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "add tweet failed: " << queryAdd.lastError();
    }

    return success;
}




bool TweetDB::removeTweet(int id)
{
    bool success = false;

    if (tweetExists(id))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM Tweets WHERE TweetID = (:TweetID)");
        queryDelete.bindValue(":TweetID", id);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove tweet failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove tweet failed: tweet doesnt exist";
    }

    return success;
}

TweetInfoType TweetDB::retrieveTweetInfo(int tweetID)
{

    QSqlQuery queryRetrieve;
    queryRetrieve.prepare("SELECT * FROM tweets WHERE tweetID = :tweetID");
    queryRetrieve.bindValue(":tweetID", tweetID);

    int tweetIDIndex = /*query.record().indexOf("tweetID");*/ 0;
    int scrapbookIDIndex = /*query.record().indexOf("Username");*/ 1;
    int contentIndex = /*query.record().indexOf("Password");*/ 2;

    int id = -1;
    int scrapbookID = -1;
    QString tweetContent = "";

    if (queryRetrieve.exec())
    {
        if(queryRetrieve.next())
        {
            id = queryRetrieve.value(tweetIDIndex).toInt();
            scrapbookID = queryRetrieve.value(scrapbookIDIndex).toInt();
            tweetContent = queryRetrieve.value(contentIndex).toString();
        }
    }
    else
    {
        qDebug() << "tweet retrieval fails:" <<queryRetrieve.lastError();
    }

    return std::make_tuple(id, scrapbookID, tweetContent);

}

bool TweetDB::tweetExists(int id) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT * FROM Tweets WHERE TweetID = (:TweetID)");
    checkQuery.bindValue(":TweetID", id);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "tweet exists failed: " << checkQuery.lastError();
    }

    return exists;
}

bool TweetDB::removeAllTweets()
{
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM Tweets");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "remove all tweets failed: " << removeQuery.lastError();
    }

    return success;
}
