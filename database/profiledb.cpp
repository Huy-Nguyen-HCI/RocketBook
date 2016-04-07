#include "profiledb.h"

ProfileDB::ProfileDB()
{
    profileDB = QSqlDatabase::addDatabase("QSQLITE");
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
    profileDB = QSqlDatabase::addDatabase("QSQLITE");
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
    if (profileDB.isOpen())
    {
        profileDB.close();
    }
}

bool ProfileDB::isOpen() const
{
    return profileDB.isOpen();
}

bool ProfileDB::addProfile(int profileID, const QString &fullName, const QString &photo, const QString &description)
{
    bool success = false;


    QSqlQuery queryAdd;
    queryAdd.prepare("INSERT INTO profiles (profileid, fullname, photo, description) VALUES (:profileid, :fullname, :photo, :description)");
    queryAdd.bindValue(":profileid", profileID);
    queryAdd.bindValue(":fullname", fullName);
    queryAdd.bindValue(":photo", photo);
    queryAdd.bindValue(":description", description);

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
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM profiles WHERE profileid = :profileid");
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

QString ProfileDB::retrieveProfileInfo(int profileID)
{
    QString profileInfo = "";

    qDebug() << "Profiles in db:";
    QSqlQuery queryRetrieve;
    queryRetrieve.prepare("SELECT * FROM profiles WHERE profileid = (:profileid)");
    queryRetrieve.bindValue(":profileid", profileID);

    int profileidIndex = /*query.record().indexOf("profileid");*/ 0;
    int fullnameIndex = /*query.record().indexOf("fullname");*/ 1;
    int photoIndex = /*query.record().indexOf("photo");*/ 2;
    int descriptionIndex = /*query.record().indexOf("description");*/ 3;

    if (queryRetrieve.exec())
    {
        if(queryRetrieve.next())
        {
            profileInfo += queryRetrieve.value(profileidIndex).toString() + " ";
            profileInfo += queryRetrieve.value(fullnameIndex).toString() + " ";
            profileInfo += queryRetrieve.value(photoIndex).toString() + " ";
            profileInfo += queryRetrieve.value(descriptionIndex).toString();
        }
    }
    else
    {
        qDebug() << "profile retrieval fails:" <<queryRetrieve.lastError();
    }

    return profileInfo;
}

QString ProfileDB::retrieveFullname (int profileID)
{
    QString fullName = "";

    qDebug() << "Profiles in db:";
    QSqlQuery queryRetrieve;
    queryRetrieve.prepare("SELECT fullname FROM profiles WHERE profileid = (:profileid)");
    queryRetrieve.bindValue(":profileid", profileID);

    int fullnameIndex = /*query.record().indexOf("fullname");*/ 1;

    if (queryRetrieve.exec())
    {
        if(queryRetrieve.next())
        {
            fullName += queryRetrieve.value(fullnameIndex).toString() + " ";
        }
    }
    else
    {
        qDebug() << "profile retrieval fails:" <<queryRetrieve.lastError();
    }

    return fullName;
}

QString ProfileDB::retrievePhoto (int profileID)
{
    QString photo = "";

    qDebug() << "Profiles in db:";
    QSqlQuery queryRetrieve;
    queryRetrieve.prepare("SELECT fullname FROM profiles WHERE profileid = (:profileid)");
    queryRetrieve.bindValue(":profileid", profileID);

    int photoIndex = /*query.record().indexOf("photo");*/ 2;

    if (queryRetrieve.exec())
    {
        if(queryRetrieve.next())
        {
            photo += queryRetrieve.value(photoIndex).toString() + " ";
        }
    }
    else
    {
        qDebug() << "profile retrieval fails:" <<queryRetrieve.lastError();
    }

    return photo;
}

QString ProfileDB::retrieveDescription (int profileID)
{
    QString description = "";

    qDebug() << "Profiles in db:";
    QSqlQuery queryRetrieve;
    queryRetrieve.prepare("SELECT description FROM profiles WHERE profileid = (:profileid)");
    queryRetrieve.bindValue(":profileid", profileID);

    int descriptionIndex = /*query.record().indexOf("description");*/ 2;

    if (queryRetrieve.exec())
    {
        if(queryRetrieve.next())
        {
            description += queryRetrieve.value(descriptionIndex).toString() + " ";
        }
    }
    else
    {
        qDebug() << "profile retrieval fails:" <<queryRetrieve.lastError();
    }

    return description;
}

bool ProfileDB::profileExists(int profileID) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT profileid FROM profiles WHERE profileid = (:profileid)");
    checkQuery.bindValue(":profileid", profileID);

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

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM profiles");

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
