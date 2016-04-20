#include "groupdb.h"

GroupDB::GroupDB()
{
    connectionName.append("groups");
    QSqlDatabase groupDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    groupDB.setDatabaseName("../database/RocketDB.sqlite");

    if (!groupDB.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

GroupDB::GroupDB(const QString &path)
{
    connectionName.append("groups");
    QSqlDatabase groupDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    groupDB.setDatabaseName(path);

    if (!groupDB.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

GroupDB::~GroupDB()
{
    QSqlDatabase::removeDatabase(connectionName);
}

bool GroupDB::isOpen() const
{
    QSqlDatabase groupDB = QSqlDatabase::database(connectionName);
    return groupDB.isOpen();
}

bool GroupDB::addGroup(int groupID, int profileID){

    bool success = false;

    QSqlQuery queryAdd(QSqlDatabase::database(connectionName));
    queryAdd.prepare("INSERT INTO Groups (GroupID, ProfileID) VALUES (:GroupID, :ProfileID)");
    queryAdd.bindValue(":GroupID", groupID);
    queryAdd.bindValue(":ProfileID", profileID);

    if(queryAdd.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "add group failed: " << queryAdd.lastError();
    }

    return success;

}

int GroupDB::getProfileID(int groupID)
{
    int profileID;

    qDebug() << "Get profileID from group:";
    QSqlQuery queryProfileID(QSqlDatabase::database(connectionName));
    queryProfileID.prepare("SELECT ProfileID FROM Groups WHERE GroupID = (:GroupID)");
    queryProfileID.bindValue(":GroupID", groupID);

    if (queryProfileID.exec())
    {
        if(queryProfileID.next())
        {
            profileID = queryProfileID.value(0).toInt();
        }
    }
    else
    {
        qDebug() << "group retrieval fails:" <<queryProfileID.lastError();
    }

    return profileID;
}

int GroupDB::getMaxGroupID()
{
    int maxID;

    qDebug() << "Get max group ID from db:";
    QSqlQuery queryMaxID(QSqlDatabase::database(connectionName));
    queryMaxID.prepare("SELECT max(GroupID) FROM Groups");

    if (queryMaxID.exec())
    {
        if(queryMaxID.next())
        {
            maxID = queryMaxID.value(0).toInt();
        }
    }
    else
    {
        qDebug() << "group retrieval fails:" <<queryMaxID.lastError();
    }

    return maxID;

}


bool GroupDB::removeAllGroups()
{
    bool success = false;

    QSqlQuery removeQuery(QSqlDatabase::database(connectionName));
    removeQuery.prepare("DELETE FROM Groups");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "remove all groups failed: " << removeQuery.lastError();
    }

    return success;
}

