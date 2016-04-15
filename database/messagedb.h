#ifndef MESSAGEDB_H
#define MESSAGEDB_H


#include <QString>
#include <QtSql>
#include <QDebug>
#include <vector>

//typedef std::tuple<int, QString, QString, int, int> AccountInfoType;

class MessageDB
{
public:
    /**
     * @brief MessageDB
     *
     * Construct a message database at ../database/accountDB.sqlite
     */
    MessageDB();
    /**
     * @brief MessageDB
     * Construct a message database, given the path and the name of the database
     * @param path full path name of the messagedb
     */
    MessageDB(const QString& path);

    /**
     * @brief ~AccountDB
     *
     * Default destructor for message database
     */
    ~MessageDB();

    /**
     * @brief isOpen
     *
     * Check whether message database is open
     * @return true if yes, false if no
     */
    bool isOpen() const;


    bool addMessage(int messageID, int chatID, int accountID, std::string message);
    bool deleteMessage(int chatID, std::string text);

    std::vector<std::string>* retrieveChatMessages(int chatID);
    std::vector<int>* retrieveChatSenders(int chatID);




//    std::vector<int> retrieveChats(int accountId);
  //  std::vector<int> retrieveMessages(int chatId);
  //  QString retrieveMessageContent(int chatId, int messageId);

private:
     QString connectionName;
};
//
#endif // MESSAGEDB_H
