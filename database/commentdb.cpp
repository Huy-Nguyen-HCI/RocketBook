#include "commentdb.h"

CommentDB::CommentDB()
{
    connectionName.append("comments");
    QSqlDatabase commentDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
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
    connectionName.append("comments");
    QSqlDatabase commentDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
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
    QSqlDatabase::removeDatabase(connectionName);
}

bool CommentDB::isOpen() const
{
    QSqlDatabase commentDB = QSqlDatabase::database(connectionName);
    return commentDB.isOpen();
}

bool CommentDB::addComment(int commentID, int accountID, int blogID, const QString &content)
{
    bool success = false;

    QSqlQuery queryAdd(QSqlDatabase::database(connectionName));
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
        QSqlQuery queryDelete(QSqlDatabase::database(connectionName));
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

CommentInfoType CommentDB::retrieveCommentInfo(int id)
{

    QSqlQuery queryRetrieve(QSqlDatabase::database(connectionName));
    queryRetrieve.prepare("SELECT * FROM Comments WHERE CommentID = :CommentID");
    queryRetrieve.bindValue(":CommentID", id);



    int commentIDIndex = /*query.record().indexOf("commentID");*/ 0;
    int blogIDIndex = /*query.record().indexOf("Username");*/ 1;
    int accountIDIndex = /*query.record().indexOf("Password");*/ 2;
    int contentIndex = 3;

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
        qDebug() << "comment retrieval fails:" <<queryRetrieve.lastError();
    }

    return std::make_tuple(commentID, accountID, blogID, content);

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
        qDebug() << "comment exists failed: " << checkQuery.lastError();
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
        qDebug() << "remove all comments failed: " << removeQuery.lastError();
    }

    return success;
}
