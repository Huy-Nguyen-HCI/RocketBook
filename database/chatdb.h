#ifndef CHATDB_H
#define CHATDB_H

#include <QString>
#include <QtSql>
#include <QDebug>
#include <vector>


class ChatDB
{
public:
    /**
     * @brief ChatDB
     *
     * Construct a chat database at ../database/RocketDB.sqlite
     */
    ChatDB();

    /**
     * @brief ChatDB
     * Construct an Chat database, given the path and the name of the database
     * @param path full path name of the Chatdb
     */
    ChatDB(const QString& path);

    /**
     * @brief ~ChatDB
     *
     * Default destructor for Chat database
     */
    ~ChatDB();

    /**
     * @brief isOpen
     *
     * Check whether Chat database is open
     * @return true if yes, false if no
     */
    bool isOpen() const;

    /**
     * @brief addToChat
     * Add a new member to chat
     *
     * @param chatID Chat Id
     * @param accountID Id of account to be added to chat
     * @return true if added, false if not added
     */
    bool addToChat(int chatID, int accountID);

    /**
     * @brief removeFromChat
     * Removes account from chat
     *
     * @param chatID Id of chosen chat
     * @param accountID Id of account to be removed from chat
     * @return true if succeeded, false if failed
     */
    bool removeFromChat(int chatID, int accountID);

    /**
     * @brief retrieveChatlist
     * Return a vector chat Ids for a given user indicating all chats the user in a part of
     *
     * @param accountId Account Id
     * @return a vector of Ids of all chats the specified account is involved in
     */
    std::vector<int>* retrieveChatList(int accountID);
    /**
     * @brief retrieveAccountsInChat
     * Return a vector including ID's of all participants of a specified chat
     *
     *
     * @param chatId Id of chat
     * @return a vector of account Ids participating in specified chat
     */
    std::vector<int>* retrieveAccountsInChat(int chatId);

    /**
     * @brief createChat
     * Creates a chat. When a chat is created, only one user is in the chat
     *
     *
     * @param accountId Account of creator of the chat
     * @return true if creation successful, false otherwise
     */
    bool createChat(int accountID);

    /**
     * @brief getMaxChatId
     * Get the maximum ID for chats
     *
     * @return the maximum used for chats
     */
    int getMaxChatID();


    /**
     * @brief inChat
     * Returns true of specified account is in specified chat
     *
     * @param chatID Id of chosen chat
     * @param accountID Id of account
     * @return true if specified account is in specified chat, false otherwise
     */
    bool inChat(int chatID, int accountID) const;

    /**
     * @brief removeAllChats
     * Remove all chats existing in the database
     * @return true if succeeded, false if failed
     */
    bool removeAllChats();



    QString connectionName;

};

#endif // CHATDB_H
