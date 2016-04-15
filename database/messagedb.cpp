#include "messagedb.h"


//structure: message Id, Chat Id, Account Id, message (text)

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

bool MessageDB::addMessage(int messageID, int chatID, int accountID, std::string message){

    bool success = false;

        QSqlQuery queryAdd(QSqlDatabase::database(connectionName));
        queryAdd.prepare("INSERT INTO Messages (MessageID, ChatID, AccountID, Message) VALUES (:MessageID, :ChatID, :AccountID, :Message)");
   //     queryAdd.bindValue(":MessageID", accountID);
   //     queryAdd.bindValue(":ChatID", username);
   //     queryAdd.bindValue(":AccountID", password);
    //    queryAdd.bindValue(":Message", profileID);

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "Failed to add message: " << queryAdd.lastError();
        }

    return success;
}

bool MessageDB::deleteMessage(int chatID, std::string text){

}

std::vector<std::string>* MessageDB::retrieveChatMessages(int chatID){

}

std::vector<int>* MessageDB::retrieveChatSenders(int chatID){

}





/**

bool MessageDB::addMessage(){

//insert:
// New Message id; same chat id; sended account Id; message


}

//message= "user has been added"

bool MessageDB::addAccountToChat(){


//Creates entry to database
//insert:
//new Message id; same chat id; creator account Id; message="Chat Created"




}


bool MessageDB::createChat(){

//insert:
//Message id=0; new chat id; creator account Id; message="Chat Created"



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
