#include "messagedb.h"


MessageDB::MessageDB()
{
    connectionName.append("messages");
    QSqlDatabase messageDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    messageDB.setDatabaseName("../database/RocketDB.sqlite");

    if (!messageDB.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

MessageDB::MessageDB(const QString &path)
{
    connectionName.append("accounts");
    QSqlDatabase MessageDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    MessageDB.setDatabaseName(path);

    if (!MessageDB.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

MessageDB::~MessageDB()
{
    QSqlDatabase::removeDatabase(connectionName);
}

bool MessageDB::isOpen() const
{
    QSqlDatabase messageDB = QSqlDatabase::database(connectionName);
    return messageDB.isOpen();
}

/**

bool MessageDB::addMessage(){

}

//message= "user has been added"
bool MessageDB::addAccountToChat(){

}

//message="you have created chat"
bool MessageDB::addChat(){

}


std::vector<int> MessageDB::retrieveChats(int accountId){

}


std::vector<int> MessageDB::retrieveAccountsInChat(int chatId){

}


std::vector<int> MessageDB::retrieveMessages(int chatId){

}


QString MessageDB::retrieveMessageContent(int chatId, int messageId){


}

**/
