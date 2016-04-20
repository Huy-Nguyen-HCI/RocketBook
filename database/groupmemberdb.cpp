#include "groupmemberdb.h"

GroupMemberDB::GroupMemberDB()
{
    connectionName.append("GroupMembers");
    QSqlDatabase groupMemberDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    groupMemberDB.setDatabaseName("../database/RocketDB.sqlite");

    if (!groupMemberDB.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

GroupMemberDB::GroupMemberDB(const QString &path)
{
    connectionName.append("GroupMembers");
    QSqlDatabase groupMemberDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    //Must name database connection

    groupMemberDB.setDatabaseName(path);

    if (!groupMemberDB.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

GroupMemberDB::~GroupMemberDB()
{
    QSqlDatabase::removeDatabase(connectionName);
}


bool GroupMemberDB::isOpen() const
{
    QSqlDatabase groupMemberDB = QSqlDatabase::database(connectionName);
    return groupMemberDB.isOpen();
}

bool GroupMemberDB::addGroupMember(int groupID, int accountID, int groupAdminRights){

    bool success = false;
    QSqlQuery queryAdd(QSqlDatabase::database(connectionName));
    queryAdd.prepare("INSERT INTO GroupMembers (GroupID, AccountID, GroupAdminRights) VALUES (:GroupID, :AccountID, :GroupAdminRights)");
    queryAdd.bindValue(":GroupID", groupID);
    queryAdd.bindValue(":AccountID", accountID);
    queryAdd.bindValue(":GroupAdminRights", groupAdminRights);

    if(queryAdd.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "add group member failed: " << queryAdd.lastError();
    }

    return success;
}

bool GroupMemberDB::groupMemberExists(int groupID, int accountID) const
{

    bool exists = false;

    QSqlQuery checkQuery(QSqlDatabase::database(connectionName));
    checkQuery.prepare("SELECT AccountID FROM GroupMembers WHERE GroupID = (:GroupID) AND AccountID = (:AccountID)");
    checkQuery.bindValue(":GroupID", groupID);
    checkQuery.bindValue(":AccountID", accountID);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "group member exists failed: " << checkQuery.lastError();
    }

    return exists;
}


bool GroupMemberDB::removeGroupMember(int groupID, int accountID){
    bool success = false;

    if (groupMemberExists(groupID, accountID))
    {
        //Deletes group member from a group
        QSqlQuery queryDelete(QSqlDatabase::database(connectionName));
        queryDelete.prepare("DELETE FROM GroupMembers WHERE GroupID = (:GroupID) AND AccountID = (:AccountID)");
        queryDelete.bindValue(":GroupID", groupID);
        queryDelete.bindValue(":AccountID", accountID);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove group member failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove group member failed: group member does not exist";
    }

    return success;}



std::vector<GroupMemberInfoType> GroupMemberDB::retrieveAllGroupMembersInfo(int groupID)
{
    QSqlQuery queryRetrieve(QSqlDatabase::database(connectionName));
    queryRetrieve.prepare("SELECT * FROM GroupMembers WHERE GroupID = :GroupID");
    queryRetrieve.bindValue(":GroupID", groupID);

    int accountIDIndex = 1;
    int groupAdminRightsIndex = 2;

    int accountID = -1;
    int groupAdminRights = -1;

    std::vector<GroupMemberInfoType> groupMemberInfo;

    if (queryRetrieve.exec())
    {
        while (queryRetrieve.next())
        {
            //retrieve each unit info
            accountID = queryRetrieve.value(accountIDIndex).toInt();
            groupAdminRights = queryRetrieve.value(groupAdminRightsIndex).toInt();

            //add a row into the vector
            groupMemberInfo.push_back(std::make_tuple(groupID, accountID, groupAdminRights));
        }
    }
    else
    {
        qDebug() << "group member retrieval fails:" <<queryRetrieve.lastError();
    }

    return groupMemberInfo;
}



bool GroupMemberDB::removeAllGroupMembers()
{
    bool success = false;

    QSqlQuery removeQuery(QSqlDatabase::database(connectionName));
    removeQuery.prepare("DELETE FROM GroupMembers");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "remove all group members failed: " << removeQuery.lastError();
    }

    return success;
}

