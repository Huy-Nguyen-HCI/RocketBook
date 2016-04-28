#include "accountdb.h"

AccountDB::AccountDB()
{
    connectionName.append("accounts");
    QSqlDatabase accountDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    accountDB.setDatabaseName("../database/RocketDB.sqlite");

    if (!accountDB.open())
    {
        //qDebug() << "Error: connection with database fail";
    }
    else
    {
        //qDebug() << "Database: connection ok";
    }
}

AccountDB::AccountDB(const QString &path)
{
    connectionName.append("accounts");
    QSqlDatabase accountDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    accountDB.setDatabaseName(path);

    if (!accountDB.open())
    {
        //qDebug() << "Error: connection with database fail";
    }
    else
    {
        //qDebug() << "Database: connection ok";
    }
}

AccountDB::AccountDB(const QString &path, const QString &connectionName)
{
    this->connectionName.append(connectionName);
    QSqlDatabase accountDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    accountDB.setDatabaseName(path);

    if (!accountDB.open())
    {
        //qDebug() << "Error: connection with database fail";
    }
    else
    {
        //qDebug() << "Database: connection ok";
    }
}

AccountDB::~AccountDB()
{
    QSqlDatabase::removeDatabase(connectionName);
}

bool AccountDB::isOpen() const
{
    QSqlDatabase accountDB = QSqlDatabase::database(connectionName);
    return accountDB.isOpen();
}

bool AccountDB::addAccount(int accountID, const QString &username, const QString &password, int profileID, int adminRights)
{
    bool success = false;

    if (!username.isEmpty() && !password.isEmpty()) {
        QSqlQuery queryAdd(QSqlDatabase::database(connectionName));
        queryAdd.prepare("INSERT INTO Accounts (AccountID, Username, Password, ProfileID, AdminRights) VALUES (:AccountID, :Username, :Password, :ProfileID, :AdminRights)");
        queryAdd.bindValue(":AccountID", accountID);
        queryAdd.bindValue(":Username", username);
        queryAdd.bindValue(":Password", password);
        queryAdd.bindValue(":ProfileID", profileID);
        queryAdd.bindValue(":AdminRights", adminRights);

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            //qDebug() << "add account failed: " << queryAdd.lastError();
        }
    }
    return success;
}




bool AccountDB::removeAccount(const QString& username)
{
    bool success = false;

    if (accountExists(username))
    {
        QSqlQuery queryDelete(QSqlDatabase::database(connectionName));
        queryDelete.prepare("DELETE FROM Accounts WHERE Username = (:Username)");
        queryDelete.bindValue(":Username", username);
        success = queryDelete.exec();

        if(!success)
        {
            //qDebug() << "remove account failed: " << queryDelete.lastError();
        }
    }
    else
    {
        //qDebug() << "remove account failed: account doesnt exist";
    }

    return success;
}

AccountInfoType AccountDB::retrieveAccountInfo(const QString& userName)
{

    //qDebug() << "Accounts in db:";
    QSqlQuery queryRetrieve(QSqlDatabase::database(connectionName));
    queryRetrieve.prepare("SELECT * FROM Accounts WHERE username = :Username");
    queryRetrieve.bindValue(":Username", userName);
    int accountIDIndex = /*query.record().indexOf("AccountID");*/ 0;
    int usernameIndex = /*query.record().indexOf("Username");*/ 1;
    int passwordIndex = /*query.record().indexOf("Password");*/ 2;
    int profileidIndex = /*query.record().indexOf("ProfileID");*/ 3;
    int adminRightsIndex = 4;

    int accountID = -1;
    QString user = "";
    QString pass = "";
    int profileID = -1;
    int adminRights = -1;

    if (queryRetrieve.exec())
    {
        if(queryRetrieve.next())
        {
            accountID = queryRetrieve.value(accountIDIndex).toInt();
            profileID = queryRetrieve.value(profileidIndex).toInt();
            user = queryRetrieve.value(usernameIndex).toString();
            pass = queryRetrieve.value(passwordIndex).toString();
            adminRights = queryRetrieve.value(adminRightsIndex).toInt();
        }
    }
    else
    {
        //qDebug() << "account retrieval fails:" <<queryRetrieve.lastError();
    }
    return std::make_tuple(accountID, user, pass, profileID, adminRights);
}

int AccountDB::retrieveAccountID(const QString& username)
{
    QString accountId;

    //qDebug() << "Accounts in db:";
    QSqlQuery queryRetrieve(QSqlDatabase::database(connectionName));
    queryRetrieve.prepare("SELECT AccountID FROM Accounts WHERE username = :Username");
    queryRetrieve.bindValue(":Username", username);

    int accountIDIndex = /*query.record().indexOf("AccountID");*/ 0;

    if (queryRetrieve.exec())
    {
        if(queryRetrieve.next())
        {
            accountId = queryRetrieve.value(accountIDIndex).toString();
        }
    }
    else
    {
        //qDebug() << "account retrieval fails:" <<queryRetrieve.lastError();
    }

    return accountId.toInt();

}


bool AccountDB::accountExists(const QString& username) const
{
    bool exists = false;

    QSqlQuery checkQuery(QSqlDatabase::database(connectionName));
    checkQuery.prepare("SELECT Username FROM Accounts WHERE Username = (:Username)");
    checkQuery.bindValue(":Username", username);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        //qDebug() << "account exists failed: " << checkQuery.lastError();
    }

    return exists;
}

bool AccountDB::removeAllAccounts()
{
    bool success = false;

    QSqlQuery removeQuery(QSqlDatabase::database(connectionName));
    removeQuery.prepare("DELETE FROM Accounts");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        //qDebug() << "remove all accounts failed: " << removeQuery.lastError();
    }

    return success;
}



int AccountDB::getMaxAccountID()
{
    int maxID;

    //qDebug() << "Get max account ID from db:";
    QSqlQuery queryMaxID(QSqlDatabase::database(connectionName));
    queryMaxID.prepare("SELECT max(AccountID) FROM Accounts");

    if (queryMaxID.exec())
    {
        if(queryMaxID.next())
        {
            maxID = queryMaxID.value(0).toInt();
        }
    }
    else
    {
        //qDebug() << "account retrieval fails:" <<queryMaxID.lastError();
    }

    return maxID;

}

QString AccountDB::getUsername(int accountID)
{
    //qDebug() << "Get username in db:";
    QSqlQuery queryUsername(QSqlDatabase::database(connectionName));
    queryUsername.prepare("SELECT Username FROM Accounts WHERE AccountID = :AccountID");
    queryUsername.bindValue(":AccountID", accountID);
    if (queryUsername.exec())
    {
        if(queryUsername.next())
        {
            return queryUsername.value(0).toString();
        }
    }
    else
    {
        //qDebug() << "username retrieval fails:" <<queryUsername.lastError();
    }

    return "";
}

int AccountDB::getProfileID(int accountID)
{
    //qDebug() << "Get profile ID in db:";
    QSqlQuery queryUsername(QSqlDatabase::database(connectionName));
    queryUsername.prepare("SELECT ProfileID FROM Accounts WHERE AccountID = :AccountID");
    queryUsername.bindValue(":AccountID", accountID);
    if (queryUsername.exec())
    {
        if(queryUsername.next())
        {
            return queryUsername.value(0).toInt();
        }
    }
    else
    {
        //qDebug() << "profile ID retrieval fails:" <<queryUsername.lastError();
    }

    return -1;
}
