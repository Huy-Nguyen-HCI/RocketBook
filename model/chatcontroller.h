#ifndef CHATCONTROLLER_H
#define CHATCONTROLLER_H

#include <iostream>
#include <sstream>
#include <QDebug>
#include <QCoreApplication>
#include "../database/chatdb.h"
#include "../database/messagedb.h"
#include "../database/accountdb.h"
#include <string>
#include "chat.h"
#include "message.h"



class ChatController
{
public:
    /**
     * @brief ChatController
     * @param dbPath Database path
     * @param accountId Account Id
     */
    ChatController(QString dbPath, int accountId);
    /**
     * @brief ChatController destuctor
     */
    ~ChatController();

    /**
     * @brief createChat
     * Creates chat
     * @param friendName Name of friend that chat will be started with
     */
    void createChat(QString friendName);

    /**
     * @brief addMemberToChat
     * Adds an friend to chat
     * @param chatId Id of chat
     * @param friendName Name of friend
     * @return True if friend has been added to chat
     */
    bool addMemberToChat(int chatId, QString friendName);
    /**
     * @brief sendMessage
     * Sends Message
     * @param chatId Id of chat
     * @param messahe Message being sent
     * @return True of message sent successfully
     */
    bool sendMessage(int chatId, QString message);
    /**
     * @brief removeUserFromChat
     * Removes user from chat
     * @param chatId Id of chat
     * @param username Name of user to be removed
     * @return True if user has been removed from chat
     */
    bool removeUserFromChat(int chatId, QString username);
    /**
     * @brief getChatIdList
     * Returns list of all chat Ids
     * @return Vector of chat Ids
     */
    std::vector<int>* getChatIdList();
    /**
     * @brief getSenderList
     * Returns list of senders for a given chat
     * @param chatId Id of chat
     * @return Vector of account Ids in the order which the messages were sent
     */
    std::vector<int>* getSenderList(int chatId);
    /**
     * @brief getMessageList
     * Returns list of messages for a given chat
     * @param chatId Id of chat
     * @return Vector of  messages for the specified chat
     */
    std::vector<QString>* getMessageList(int chatId);

    /**
     * @brief Updates chat and message objects to agree with the database
     */
    void updateChats();

    /**
     * @brief getChatIdList
     * Returns std string list of messages for a given chat
     * @param chatId Id of chat
     * @return Vector of messages for the specified chat
     */
    QStringList getChatIdListGUI();
    /**
     * @brief getMessageListGUI
     * Returns a QStringList of messages for a given chat
     * @param chatId Id of chat
     * @return QStringList of messages for the specified chat
     */
    QStringList getMessageListGUI(int chatId);
    /**
     * @brief getChatMembersGUI
     * Returns a QStringList of chat members for a given chat
     * @param chatId Id of chat
     * @return QStringList of usernames in the order which the messages were sent
     */
    QStringList getChatMembersGUI(int chatId);

    std::vector<Chat*> chatList;


private:
    AccountDB* accountDB;
    ChatDB* chatDB;
    MessageDB* messageDB;
    QString username;
    int accountId;

    /**
     * @brief cleanUp
     * Deletes chats with only one participant.
     * Was not immpemented in case the user wanted to keep chat,
     * but the functionality was left in the model.
     */
    void cleanUp();
};

#endif // CHATCONTROLLER_H
