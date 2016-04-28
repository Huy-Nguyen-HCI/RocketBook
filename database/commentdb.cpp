#include "commentdb.h"

CommentDB::CommentDB(): PostDB::PostDB()
{
    connectionName.append("comments");
    QSqlDatabase commentDB;
    if (!QSqlDatabase::contains(connectionName)) {
        commentDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    } else {
        commentDB = QSqlDatabase::database(connectionName);
    }
    commentDB.setDatabaseName("CommentDB.sqlite");

    if (!commentDB.open())
    {
        //qDebug() << "Error: connection with database fail";
    }
    else
    {
        //qDebug() << "Database: connection ok";
    }
}

CommentDB::CommentDB(const QString &path): PostDB::PostDB()
{
    connectionName.append("comments");
    QSqlDatabase commentDB;
    if (!QSqlDatabase::contains(connectionName)) {
        commentDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    } else {
        commentDB = QSqlDatabase::database(connectionName);
    }
    commentDB.setDatabaseName(path);

    if (!commentDB.open())
    {
        //qDebug() << "Error: connection with database fail";
    }
    else
    {
        //qDebug() << "Database: connection ok";
    }
}

CommentDB::~CommentDB()
{
    QSqlDatabase::removeDatabase(connectionName);
}


bool CommentDB::addComment(int commentID, int accountID, int blogID, const QString &content)
{
    bool success = false;

    QSqlQuery queryAdd(QSqlDatabase::database(connectionName));
    queryAdd.prepare("INSERT INTO Comments (CommentID, AccountID, BlogID, CommentContent) VALUES (:CommentID, :AccountID, :BlogID, :CommentContent)");
    queryAdd.bindValue(":CommentID", commentID);
    queryAdd.bindValue(":AccountID", accountID);
    queryAdd.bindValue(":BlogID", blogID);
    queryAdd.bindValue(":CommentContent", content);

    if(queryAdd.exec())
    {
        success = true;
    }
    else
    {
        //qDebug() << "add comment failed: " << queryAdd.lastError();
    }

    return success;
}




bool CommentDB::removeComment(int id)
{
    bool success = false;

    if (commentExists(id))
    {
        QSqlQuery queryDelete(QSqlDatabase::database(connectionName));
        queryDelete.prepare("DELETE FROM Comments WHERE CommentID = (:CommentID)");
        queryDelete.bindValue(":CommentID", id);
        success = queryDelete.exec();

        if(!success)
        {
            //qDebug() << "remove comment failed: " << queryDelete.lastError();
        }
    }
    else
    {
        //qDebug() << "remove comment failed: comment doesnt exist";
    }

    return success;
}

CommentInfoType CommentDB::retrieveCommentInfo(int id)
{

    QSqlQuery queryRetrieve(QSqlDatabase::database(connectionName));
    queryRetrieve.prepare("SELECT * FROM Comments WHERE CommentID = :CommentID");
    queryRetrieve.bindValue(":CommentID", id);



    int commentIDIndex = /*query.record().indexOf("CommentID");*/ 0;
    int accountIDIndex = /*query.record().indexOf("AccountID");*/ 1;
    int blogIDIndex = /*query.record().indexOf("BlogID");*/ 2;
    int contentIndex = /*query.record().indexOf("CommentContent");*/3;

    int commentID = -1;
    int accountID = -1;
    int blogID = -1;
    QString content = "";

    if (queryRetrieve.exec())
    {
        if(queryRetrieve.next())
        {
            commentID = queryRetrieve.value(commentIDIndex).toInt();
            accountID = queryRetrieve.value(accountIDIndex).toInt();
            blogID = queryRetrieve.value(blogIDIndex).toInt();
            content = queryRetrieve.value(contentIndex).toString();
        }
    }
    else
    {
        //qDebug() << "comment retrieval fails:" <<queryRetrieve.lastError();
    }

    return std::make_tuple(commentID, accountID, blogID, content);

}

std::vector<CommentInfoType> CommentDB::retrieveAllCommentInfo(int blogID)
{
    QSqlQuery queryRetrieve(QSqlDatabase::database(connectionName));
    queryRetrieve.prepare("SELECT * FROM Comments WHERE BlogID = :BlogID");
    queryRetrieve.bindValue(":BlogID", blogID);

    int commentIDIndex = /*query.record().indexOf("CommentID");*/ 0;
    int accountIDIndex = /*query.record().indexOf("AccountID");*/ 1;
    int blogIDIndex = /*query.record().indexOf("ScrapbookID");*/ 2;
    int contentIndex = /*query.record().indexOf("CommentContent");*/ 3;

    int id = -1;
    int accountID = -1;
    int newBlogID = -1;
    QString commentContent = "";

    std::vector<CommentInfoType> commentInfo;

    if (queryRetrieve.exec())
    {
        while (queryRetrieve.next())
        {
            //retrieve each unit info
            id = queryRetrieve.value(commentIDIndex).toInt();
            accountID = queryRetrieve.value(accountIDIndex).toInt();
            newBlogID = queryRetrieve.value(blogIDIndex).toInt();
            commentContent = queryRetrieve.value(contentIndex).toString();

            //add a row into the vector
            commentInfo.push_back(std::make_tuple(id, accountID, newBlogID, commentContent));
        }
    }
    else
    {
        //qDebug() << "comment retrieval fails:" <<queryRetrieve.lastError();
    }

    return commentInfo;
}

bool CommentDB::commentExists(int id) const
{
    bool exists = false;

    QSqlQuery checkQuery(QSqlDatabase::database(connectionName));
    checkQuery.prepare("SELECT * FROM Comments WHERE CommentID = (:CommentID)");
    checkQuery.bindValue(":CommentID", id);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        //qDebug() << "comment exists failed: " << checkQuery.lastError();
    }

    return exists;
}

bool CommentDB::removeAllComments()
{
    bool success = false;

    QSqlQuery removeQuery(QSqlDatabase::database(connectionName));
    removeQuery.prepare("DELETE FROM Comments");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        //qDebug() << "remove all comments failed: " << removeQuery.lastError();
    }

    return success;
}
