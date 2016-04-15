#include "chatdb.h"


ChatDB::ChatDB()
{
    connectionName.append("chats");
    QSqlDatabase chatDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    chatDB.setDatabaseName("../database/RocketDB.sqlite");

    if (!chatDB.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

ChatDB::ChatDB(const QString &path)
{
    connectionName.append("chats");
    QSqlDatabase chatDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    chatDB.setDatabaseName(path);

    if (!chatDB.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

ChatDB::~ChatDB()
{
    QSqlDatabase::removeDatabase(connectionName);
}

bool ChatDB::isOpen() const
{
    QSqlDatabase chatDB = QSqlDatabase::database(connectionName);
    return chatDB.isOpen();
}

bool ChatDB::addToChat(int chatID, int accountID){

    bool success = false;

    QSqlQuery queryAdd(QSqlDatabase::database(connectionName));
    queryAdd.prepare("INSERT INTO Chats (ChatID, AccountID) VALUES (:ChatID, :AccountID)");
    queryAdd.bindValue(":ChatID", chatID);
    queryAdd.bindValue(":AccountID", accountID);

    if(queryAdd.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "add user to chat failed: " << queryAdd.lastError();
    }

    return success;
}

bool ChatDB::removeFromChat(int chatID, int accountID){
    bool success = false;

    if (inChat(chatID, accountID))
    {
        //Deletes user from chat
        QSqlQuery queryDelete(QSqlDatabase::database(connectionName));
        queryDelete.prepare("DELETE FROM Chats WHERE ChatID = (:ChatID) AND AccountID = (:AccountID)");
        queryDelete.bindValue(":ChatID", chatID);
        queryDelete.bindValue(":AccountID", accountID);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove from chat failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove from chat failed: account is not in chat";
    }

    return success;


}

bool ChatDB::inChat(int chatID, int accountID) const
{

    bool exists = false;

    QSqlQuery checkQuery(QSqlDatabase::database(connectionName));
    checkQuery.prepare("SELECT AccountID FROM Chats WHERE Chat = (:ChatID) AND AccountID = (:AccountID)");
    checkQuery.bindValue(":ChatID", chatID);
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
        qDebug() << "Account in chat failed: " << checkQuery.lastError();
    }

    return exists;
}



std::vector<int>* ChatDB::retrieveChatList(int accountID){

    std::vector<int>* chatList= new std::vector<int>();

    qDebug() << "Chats in db:";
    QSqlQuery queryRetrieve(QSqlDatabase::database(connectionName));
    queryRetrieve.prepare("SELECT ChatID FROM Chats WHERE AccountID = (:AccountID)");
    queryRetrieve.bindValue(":AccountID", accountID);

    int chatIdIndex = /*query.record().indexOf("ChatID"); */ 0;

    if (queryRetrieve.exec())
    {
        while(queryRetrieve.next())
        {
            chatList->push_back(queryRetrieve.value(chatIdIndex).toInt());
        }
    }

    else
    {
        qDebug() << "Chat retrieval fails:" <<queryRetrieve.lastError();
    }

    return chatList;

}

std::vector<int>* ChatDB::retrieveAccountsInChat(int chatID){

    std::vector<int>* accountList= new std::vector<int>();

    qDebug() << "Chats in db:";
    QSqlQuery queryRetrieve(QSqlDatabase::database(connectionName));
    queryRetrieve.prepare("SELECT ChatID FROM Chats WHERE ChatID = (:ChatID)");
    queryRetrieve.bindValue(":ChatID", chatID);

    int accountIdIndex = /*query.record().indexOf("AccountID"); */ 0;

    if (queryRetrieve.exec())
    {
        while(queryRetrieve.next())
        {
            accountList->push_back(queryRetrieve.value(accountIdIndex).toInt());
        }
    }

    else
    {
        qDebug() << "Chat retrieval fails:" <<queryRetrieve.lastError();
    }

    return accountList;

}

bool ChatDB::removeAllChats()
{
    bool success = false;

    QSqlQuery removeQuery(QSqlDatabase::database(connectionName));
    removeQuery.prepare("DELETE FROM Chats");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "remove all chats failed: " << removeQuery.lastError();
    }

    return success;
}
