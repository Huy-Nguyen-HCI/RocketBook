#include "profiledb.h"

ProfileDB::ProfileDB()
{
    connectionName.append("Profiles");
    QSqlDatabase profileDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    profileDB.setDatabaseName("../database/RocketDB.sqlite");

    if (!profileDB.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }

}

ProfileDB::ProfileDB(const QString &path)
{
    connectionName.append("Profiles");
    QSqlDatabase profileDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    profileDB.setDatabaseName(path);

    if (!profileDB.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

ProfileDB::~ProfileDB()
{
    QSqlDatabase::removeDatabase(connectionName);
}

bool ProfileDB::isOpen() const
{
    QSqlDatabase profileDB = QSqlDatabase::database(connectionName);
    return profileDB.isOpen();
}

bool ProfileDB::addProfile(int profileID, const QString &fullName, const QString &photo, const QString &description, int scrapbookID)
{
    bool success = false;


    QSqlQuery queryAdd(QSqlDatabase::database(connectionName));
    queryAdd.prepare("INSERT INTO Profiles (ProfileID, FullName, Photo, Description) VALUES (:ProfileID, :FullName, :Photo, :Description, :Scrapbook)");
    queryAdd.bindValue(":ProfileID", profileID);
    queryAdd.bindValue(":FullName", fullName);
    queryAdd.bindValue(":Photo", photo);
    queryAdd.bindValue(":Description", description);
    queryAdd.bindValue(":ScrapbookID", scrapbookID);

    if(queryAdd.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "add profile failed: " << queryAdd.lastError();
    }

    return success;
}

bool ProfileDB::removeProfile(int profileID)
{
    bool success = false;

    if (profileExists(profileID))
    {
        QSqlQuery queryDelete(QSqlDatabase::database(connectionName));
        queryDelete.prepare("DELETE FROM Profiles WHERE ProfileID = (:ProfileID)");
        queryDelete.bindValue(":profileid", profileID);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove profile failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove profile failed: profile doesnt exist";
    }

    return success;
}

ProfileInfoType ProfileDB::retrieveProfileInfo(int profileID)
{

    qDebug() << "Profiles in db:";
    QSqlQuery queryRetrieve(QSqlDatabase::database(connectionName));
    queryRetrieve.prepare("SELECT * FROM Profiles WHERE ProfileID = (:ProfileID)");
    queryRetrieve.bindValue(":profileid", profileID);

    int profileidIndex = /*query.record().indexOf("profileid");*/ 0;
    int fullnameIndex = /*query.record().indexOf("fullname");*/ 1;
    int photoIndex = /*query.record().indexOf("photo");*/ 2;
    int descriptionIndex = /*query.record().indexOf("description");*/ 3;
    int scrapbookIDIndex = 4;

    int id = -1;
    QString fullname = "";
    QString photo = "";
    QString description = "";
    int scrapbookID = -1;

    if (queryRetrieve.exec())
    {
        if(queryRetrieve.next())
        {
            id = queryRetrieve.value(profileidIndex).toInt();
            fullname = queryRetrieve.value(fullnameIndex).toString();
            photo = queryRetrieve.value(photoIndex).toString();
            description = queryRetrieve.value(descriptionIndex).toString();
            scrapbookID = queryRetrieve.value(scrapbookIDIndex).toInt();
        }
    }
    else
    {
        qDebug() << "profile retrieval fails:" <<queryRetrieve.lastError();
    }

    return std::make_tuple(id, fullname, photo, description, scrapbookID);
}

QString ProfileDB::retrieveFullname (int profileID)
{
    ProfileInfoType info = retrieveProfileInfo(profileID);
    return std::get<1>(info);
}

QString ProfileDB::retrievePhoto (int profileID)
{
    ProfileInfoType info = retrieveProfileInfo(profileID);
    return std::get<2>(info);
}

QString ProfileDB::retrieveDescription (int profileID)
{
    ProfileInfoType info = retrieveProfileInfo(profileID);
    return std::get<3>(info);
}

bool ProfileDB::profileExists(int profileID) const
{
    bool exists = false;

    QSqlQuery checkQuery(QSqlDatabase::database(connectionName));
    checkQuery.prepare("SELECT ProfileID FROM Profiles WHERE ProfileID = (:ProfileID)");
    checkQuery.bindValue(":ProfileID", profileID);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "profile exists failed: " << checkQuery.lastError();
    }

    return exists;
}

bool ProfileDB::removeAllProfiles()
{
    bool success = false;

    QSqlQuery removeQuery(QSqlDatabase::database(connectionName));
    removeQuery.prepare("DELETE FROM Profiles");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "remove all profiles failed: " << removeQuery.lastError();
    }

    return success;
}

int ProfileDB::getMaxProfileID()
{
    int maxID = -1;

    qDebug() << "Get max profile ID from db:";
    QSqlQuery queryMaxID(QSqlDatabase::database(connectionName));
    queryMaxID.prepare("SELECT max(ProfileID) FROM Profiles");

    if (queryMaxID.exec())
    {
        if(queryMaxID.next())
        {
            maxID = queryMaxID.value(0).toInt();
        }
    }
    else
    {
        qDebug() << "profile ID max fails:" <<queryMaxID.lastError();
    }

    return maxID;
}

int ProfileDB::getMaxScrapbookID()
{
    int maxID = -1;

    qDebug() << "Get max profile ID from db:";
    QSqlQuery queryMaxID(QSqlDatabase::database(connectionName));
    queryMaxID.prepare("SELECT max(ScrapbookID) FROM Profiles");

    if (queryMaxID.exec())
    {
        if(queryMaxID.next())
        {
            maxID = queryMaxID.value(0).toInt();
        }
    }
    else
    {
        qDebug() << "profile ID max fails:" <<queryMaxID.lastError();
    }

    return maxID;
}
