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
     * @brief ~MessageDB
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


    /**
     * @brief addMessage
     * Add a new message to message database table
     *
     * @param messageID Message Id.
     * @param chatID Chat Id
     * @param accountID Id of sender
     * @param &message Message being sent
     * @return true if added, false if not added
     */
    bool addMessage(int messageID, int chatID, int accountID, const QString &message);
    /**
     * @brief deleteMessage
     * Deletes a specific message from a specific chat
     *
     * @param chatID Id of chosen chat
     * @param messageID Id of choosen message
     * @return true if succeeded, false if failed
     */
    bool deleteMessage(int chatID, int messageID);

    /**
     * @brief retrieveChatMessages
     * Return a vector of strings including ID's of all of the message in a chat
     *
     * @param chatId Id of chat which all messages will be retrieved from
     * @return a vector of all messages in specified chat
     */
    std::vector<QString>* retrieveChatMessages(int chatID);

    /**
     * @brief retrieveChatSenders
     * Return a vector including ID's of all senders of message in a chat in the same order
     * as message were sent.
     *
     * Example:
     * ChatMessages<Joe: Hi> <Ha: Hi> <Joe: how are you> <Ha: I'm good>
     * ChatSenders<Joe Id> <Ha Id> <Joe Id> <Ha Id>
     *
     * @param chatId Id of chat which all messages will be retrieved from
     * @return a vector sender Id's corresponding to messages sent
     */
    std::vector<int>* retrieveChatSenders(int chatID);
    /**
     * @brief getMaxMessageID
     * Get the maximum ID for messages in specified chat
     *
     * @param chatId Id of specified chat which max message Id will be retrieved from
     * @return the maximum used for messages in chat
     */
    int getMaxMessageID(int chatId);


private:
     QString connectionName;
};
//
#endif // MESSAGEDB_H
