#include "multimediadb.h"

MultimediaDB::MultimediaDB(): PostDB::PostDB()
{
    connectionName.append("multimedia");
    QSqlDatabase multimediaDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    multimediaDB.setDatabaseName("MultimediaDB.sqlite");

    if (!multimediaDB.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

MultimediaDB::MultimediaDB(const QString &path): PostDB::PostDB()
{
    connectionName.append("multimedia");
    QSqlDatabase multimediaDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    multimediaDB.setDatabaseName(path);

    if (!multimediaDB.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

MultimediaDB::~MultimediaDB()
{
    QSqlDatabase::removeDatabase(connectionName);
}

bool MultimediaDB::isOpen() const
{
    QSqlDatabase multimediaDB = QSqlDatabase::database(connectionName);
    return multimediaDB.isOpen();
}

bool MultimediaDB::addMultimedia(int multimediaID,
                                 int accountID,
                                 int scrapbookID,
                                 const QString &multimediaTitle,
                                 const QString &multimediaDescription,
                                 const QString &multimediaContent,
                                 int privacy)
{
    bool success = false;

    QSqlQuery queryAdd(QSqlDatabase::database(connectionName));
    queryAdd.prepare("INSERT INTO Multimedias (MultimediaID, AccountID, ScrapbookID, MultimediaTitle, MultimediaDescription, MultimediaContent, Privacy) VALUES (:MultimediaID, :AccountID, :ScrapbookID, :MultimediaTitle, :MultimediaDescription, :MultimediaContent, :Privacy)");
    queryAdd.bindValue(":MultimediaID", multimediaID);
    queryAdd.bindValue(":AccountID", accountID);
    queryAdd.bindValue(":ScrapbookID", scrapbookID);
    queryAdd.bindValue(":MultimediaTitle", multimediaTitle);
    queryAdd.bindValue(":MultimediaDescription", multimediaDescription);
    queryAdd.bindValue(":MultimediaContent", multimediaContent);
    queryAdd.bindValue(":Privacy", privacy);

    if(queryAdd.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "add Multimedia failed: " << queryAdd.lastError();
    }

    return success;
}




bool MultimediaDB::removeMultimedia(int id)
{
    bool success = false;

    if (multimediaExists(id))
    {
        QSqlQuery queryDelete(QSqlDatabase::database(connectionName));
        queryDelete.prepare("DELETE FROM Multimedias WHERE MultimediaID = (:MultimediaID)");
        queryDelete.bindValue(":MultimediaID", id);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove Multimedias failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove Multimedias failed: Multimedia doesnt exist";
    }

    return success;
}

MultimediaInfoType MultimediaDB::retrieveMultimediaInfo(int id)
{

    QSqlQuery queryRetrieve(QSqlDatabase::database(connectionName));
    queryRetrieve.prepare("SELECT * FROM Multimedias WHERE MultimediaID = :MultimediaID");
    queryRetrieve.bindValue(":MultimediaID", id);


    int multimediaIDIndex = /*query.record().indexOf("MultimediaID");*/ 0;
    int accountIDIndex = /*query.record().indexOf("MultimediaID");*/ 1;
    int scrapbookIDIndex = /*query.record().indexOf("Username");*/ 2;
    int multimediaTitleIndex = /*query.record().indexOf("Password");*/ 3;
    int multimediaDescriptionIndex = 4;
    int multimediaContentIndex = 5;
    int privacyIndex = 6;

    int multimediaID = -1;
    int accountID = -1;
    int scrapbookID = -1;
    QString title = "";
    QString description = "";
    QString content = "";
    int privacy = -1;

    if (queryRetrieve.exec())
    {
        if(queryRetrieve.next())
        {
            multimediaID = queryRetrieve.value(multimediaIDIndex).toInt();
            accountID = queryRetrieve.value(accountIDIndex).toInt();
            scrapbookID = queryRetrieve.value(scrapbookIDIndex).toInt();
            title = queryRetrieve.value(multimediaTitleIndex).toString();
            description = queryRetrieve.value(multimediaDescriptionIndex).toString();
            content = queryRetrieve.value(multimediaContentIndex).toString();
            privacy = queryRetrieve.value(privacyIndex).toInt();
        }
    }
    else
    {
        qDebug() << "Multimedia retrieval fails:" <<queryRetrieve.lastError();
    }

    return std::make_tuple(multimediaID,
                           accountID,
                           scrapbookID,
                           title,
                           description,
                           content,
                           privacy);

}

bool MultimediaDB::multimediaExists(int id) const
{
    bool exists = false;

    QSqlQuery checkQuery(QSqlDatabase::database(connectionName));
    checkQuery.prepare("SELECT * FROM Multimedias WHERE MultimediaID = (:MultimediaID)");
    checkQuery.bindValue(":MultimediaID", id);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "Multimedia exists failed: " << checkQuery.lastError();
    }

    return exists;
}

bool MultimediaDB::removeAllMultimedias()
{
    bool success = false;

    QSqlQuery removeQuery(QSqlDatabase::database(connectionName));
    removeQuery.prepare("DELETE FROM Multimedias");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "remove all Multimedias failed: " << removeQuery.lastError();
    }

    return success;
}
