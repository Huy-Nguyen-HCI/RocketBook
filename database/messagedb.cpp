#include "messagedb.h"


//structure: message Id, Chat Id, Account Id, message (text)

MessageDB::MessageDB()
{
    connectionName.append("messages");
    QSqlDatabase messageDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    messageDB.setDatabaseName("../database/RocketDB.sqlite");

    if (!messageDB.open())
    {
        //qDebug() << "Error: connection with database fail";
    }
    else
    {
        //qDebug() << "Database: connection ok";
    }
}

MessageDB::MessageDB(const QString &path)
{
    connectionName.append("accounts");
    QSqlDatabase MessageDB = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    MessageDB.setDatabaseName(path);

    if (!MessageDB.open())
    {
        //qDebug() << "Error: connection with database fail";
    }
    else
    {
        //qDebug() << "Database: connection ok";
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

bool MessageDB::addMessage(int messageID, int chatID, int accountID, const QString &message){

    bool success = false;

        QSqlQuery queryAdd(QSqlDatabase::database(connectionName));
        queryAdd.prepare("INSERT INTO Messages (MessageID, ChatID, AccountID, Message) VALUES (:MessageID, :ChatID, :AccountID, :Message)");
        queryAdd.bindValue(":MessageID", messageID);
        queryAdd.bindValue(":ChatID", chatID);
        queryAdd.bindValue(":AccountID", accountID);
        queryAdd.bindValue(":Message", message);

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            //qDebug() << "Failed to add message: " << queryAdd.lastError();
        }

        return success;
}

bool MessageDB::deleteMessage(int chatID,  int messageID){


        bool success = false;



        QSqlQuery queryDelete(QSqlDatabase::database(connectionName));
        queryDelete.prepare("DELETE FROM Messages WHERE ChatID = (:ChatID) AND MessageID = (:MessageID)");
        queryDelete.bindValue(":ChatID", chatID);
        queryDelete.bindValue(":MessageID", messageID);
        success = queryDelete.exec();

        if(!success)
        {
            //qDebug() << "remove account failed: " << queryDelete.lastError();
        }

        else
        {
            //qDebug() << "remove account failed: account doesnt exist";
        }

        return success;

}

std::vector<QString>* MessageDB::retrieveChatMessages(int chatID){

    std::vector<QString>* messageList= new std::vector<QString>();

    //qDebug() << "Messeges in chat:";
    QSqlQuery queryRetrieve(QSqlDatabase::database(connectionName));
    queryRetrieve.prepare("SELECT Message FROM Messages WHERE ChatID = (:ChatID)");
    queryRetrieve.bindValue(":ChatID", chatID);

    int messageIndex = /*query.record().indexOf("Message"); */ 0;

    if (queryRetrieve.exec())
    {
        while(queryRetrieve.next())
        {
            messageList->push_back(queryRetrieve.value(messageIndex).toString());
        }
    }

    else
    {
        //qDebug() << "message retrieval failed:" <<queryRetrieve.lastError();
    }

    return messageList;


}

std::vector<int>* MessageDB::retrieveChatSenders(int chatID){

    std::vector<int>* senderList= new std::vector<int>();

    //qDebug() << "Senders of Messages in chat:";
    QSqlQuery queryRetrieve(QSqlDatabase::database(connectionName));
    queryRetrieve.prepare("SELECT AccountID FROM Messages WHERE ChatID = (:ChatID)");
    queryRetrieve.bindValue(":ChatID", chatID);

    int senderIDIndex = /*query.record().indexOf("Message"); */ 0;

    if (queryRetrieve.exec())
    {
        while(queryRetrieve.next())
        {
            senderList->push_back(queryRetrieve.value(senderIDIndex).toInt());
        }
    }

    else
    {
        //qDebug() << "account retrieval failed:" <<queryRetrieve.lastError();
    }

    return senderList;


}

int MessageDB::getMaxMessageID(int chatId)
{
    int maxID;

    //qDebug() << "Get max messageID from chat from db:";
    QSqlQuery queryMaxID(QSqlDatabase::database(connectionName));
    queryMaxID.prepare("SELECT max(MessageID) FROM Messages WHERE ChatID = (:ChatID)");
    queryMaxID.bindValue(":ChatID", chatId);

    if (queryMaxID.exec())
    {
        if(queryMaxID.next())
        {
            maxID = queryMaxID.value(0).toInt();
        }
    }
    else
    {
        //qDebug() << "message retrieval fails:" <<queryMaxID.lastError();
    }

    return maxID;

}
