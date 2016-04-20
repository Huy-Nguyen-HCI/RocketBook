#include "postdb.h"


bool PostDB::isOpen() const {
    QSqlDatabase database = QSqlDatabase::database(connectionName);
    return database.isOpen();

}
int PostDB::getMaxPostID()
{
    int maxID;

    qDebug() << "Max postID in db:";
    QSqlQuery queryMaxID(QSqlDatabase::database(connectionName));
    queryMaxID.prepare("SELECT max(BlogID) FROM (SELECT BlogID FROM Blogs UNION SELECT MultimediaID FROM Multimedias UNION SELECT TweetID FROM Tweets UNION SELECT CommentID FROM Comments)");

    if (queryMaxID.exec())
    {
        if(queryMaxID.next())
        {
            maxID = queryMaxID.value(0).toInt();
        }
    }
    else
    {
        qDebug() << "Max PostID fails:" <<queryMaxID.lastError();
    }

    return maxID;
}
