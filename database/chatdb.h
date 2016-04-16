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


    bool addToChat(int chatID, int accountID);
    bool removeFromChat(int chatID, int accountID);
    std::vector<int>* retrieveChatList(int accountID);
    std::vector<int>* retrieveAccountsInChat(int chatId);
    bool createChat(int accountID);

    int getMaxChatID();


    bool inChat(int chatID, int accountID) const;


    bool removeAllChats();



    QString connectionName;

};

#endif // CHATDB_H
