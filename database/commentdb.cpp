#include "commentdb.h"

CommentDB::CommentDB()
{
    commentDB = QSqlDatabase::addDatabase("QSQLITE");
    commentDB.setDatabaseName("CommentDB.sqlite");

    if (!commentDB.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

CommentDB::CommentDB(const QString &path)
{
    commentDB = QSqlDatabase::addDatabase("QSQLITE");
    commentDB.setDatabaseName(path);

    if (!commentDB.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

CommentDB::~CommentDB()
{
    if (commentDB.isOpen())
    {
        commentDB.close();
    }
}

bool CommentDB::isOpen() const
{
    return commentDB.isOpen();
}

bool CommentDB::addComment(int commentID, int accountID, int blogID, const QString &content)
{
    bool success = false;

    QSqlQuery queryAdd;
    queryAdd.prepare("INSERT INTO Comments (CommentID, AccountID, BlogID, Content) VALUES (:CommentID, :AccountID, :BlogID, :Content)");
    queryAdd.bindValue(":CommentID", commentID);
    queryAdd.bindValue(":AccountID", accountID);
    queryAdd.bindValue(":BlogID", blogID);
    queryAdd.bindValue(":Content", content);

    if(queryAdd.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "add comment failed: " << queryAdd.lastError();
    }

    return success;
}




bool CommentDB::removeComment(int id)
{
    bool success = false;

    if (commentExists(id))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM Comments WHERE CommentID = (:CommentID)");
        queryDelete.bindValue(":CommentID", id);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove comment failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove comment failed: comment doesnt exist";
    }

    return success;
}

QString CommentDB::retrieveCommentInfo(int id)
{
    QString commentInfo = "";

    QSqlQuery queryRetrieve;
    queryRetrieve.prepare("SELECT * FROM Comments WHERE CommentID = :CommentID");
    queryRetrieve.bindValue(":CommentID", id);



    int commentIDIndex = /*query.record().indexOf("commentID");*/ 0;
    int usernameIndex = /*query.record().indexOf("Username");*/ 1;
    int contentIndex = /*query.record().indexOf("Password");*/ 2;

    if (queryRetrieve.exec())
    {
        if(queryRetrieve.next())
        {
            commentInfo += queryRetrieve.value(commentIDIndex).toString() + " ";
            commentInfo += queryRetrieve.value(usernameIndex).toString() + " ";
            commentInfo += queryRetrieve.value(contentIndex).toString();
        }
    }
    else
    {
        qDebug() << "comment retrieval fails:" <<queryRetrieve.lastError();
    }

    return commentInfo;

}

bool CommentDB::commentExists(int id) const
{
    bool exists = false;

    QSqlQuery checkQuery;
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
        qDebug() << "comment exists failed: " << checkQuery.lastError();
    }

    return exists;
}

bool CommentDB::removeAllComments()
{
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM Comments");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "remove all comments failed: " << removeQuery.lastError();
    }

    return success;
}
