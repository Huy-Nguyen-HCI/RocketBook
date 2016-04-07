#include "multimediaDB.h"

MultimediaDB::MultimediaDB()
{
    multimediaDB = QSqlDatabase::addDatabase("QSQLITE");
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

MultimediaDB::MultimediaDB(const QString &path)
{
    multimediaDB = QSqlDatabase::addDatabase("QSQLITE");
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
    if (multimediaDB.isOpen())
    {
        multimediaDB.close();
    }
}

bool MultimediaDB::isOpen() const
{
    return multimediaDB.isOpen();
}

bool MultimediaDB::addMultimedia(int multimediaID, int scrapbookID, QString multimediaTitle, QString multimediaDescription, QString multimediaContent)
{
    bool success = false;

    QSqlQuery queryAdd;
    queryAdd.prepare("INSERT INTO Multimedias (MultimediaID, ScrapbookID, MultimediaTitle, MultimediaDescription, MultimediaContent) VALUES (:MultimediaID, :ScrapbookID, :MultimediaTitle, :MultimediaDescription, :MultimediaContent)");
    queryAdd.bindValue(":MultimediaID", multimediaID);
    queryAdd.bindValue(":ScrapbookID", scrapbookID);
    queryAdd.bindValue(":MultimediaTitle", multimediaTitle);
    queryAdd.bindValue(":MultimediaDescription", multimediaDescription);
    queryAdd.bindValue(":MultimediaContent", multimediaContent);

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
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM Multimedias WHERE MultimediaID = (:MultimediaID)");
        queryDelete.bindValue(":MultimediaID", id);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove Multimedia failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove Multimedia failed: Multimedia doesnt exist";
    }

    return success;
}

//QString MultimediaDB::retrieveMultimediaInfo(int id)
//{
//    QString multimediaInfo = "";

//    QSqlQuery queryRetrieve;
//    queryRetrieve.prepare("SELECT * FROM Multimedias WHERE MultimediaID = :MultimediaID");
//    queryRetrieve.bindValue(":MultimediaID", id);



//    int multimediaIDIndex = /*query.record().indexOf("MultimediaID");*/ 0;
//    int scrapbookIDIndex = /*query.record().indexOf("Username");*/ 1;
//    int multimediaTitleIndex = /*query.record().indexOf("Password");*/ 2;
//    int multimediaDescriptionIndex = 3;
//    int multimediaContentIndex = 4;

//    if (queryRetrieve.exec())
//    {
//        if(queryRetrieve.next())
//        {
//            MultimediaInfo += queryRetrieve.value(MultimediaIDIndex).toString() + " ";
//            MultimediaInfo += queryRetrieve.value(usernameIndex).toString() + " ";
//            MultimediaInfo += queryRetrieve.value(contentIndex).toString();
//        }
//    }
//    else
//    {
//        qDebug() << "Multimedia retrieval fails:" <<queryRetrieve.lastError();
//    }

//    return multimediaInfo;

//}

bool MultimediaDB::multimediaExists(int id) const
{
    bool exists = false;

    QSqlQuery checkQuery;
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

    QSqlQuery removeQuery;
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
