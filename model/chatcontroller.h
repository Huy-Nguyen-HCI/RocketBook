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
    ChatController(QString dbPath, int accountId);
    ~ChatController();

    void run();
    int selectChat();   /**< used in terminal */
    void createChat();
    void addMemberToChat(int chatId, QString friendName);   /**< user in terminal */
    void sendMessage(int chatId);
    void displayMessages(int chatId);
    void removeUserFromChat(int chatId, QString friendName);    /**< used in terminal */
    void deleteMessage(int chatId);
    std::vector<int>* getChatIdList();
    std::vector<int>* getSenderList(int chatId);
    std::vector<QString>* getMessageList(int chatId);
    void updateChats();
QStringList getChatIdListGUI();

    int requestInput();
    int requestInput2();
    int userPicksChat();
    std::string userEntersMessage();
    std::string askUserName();

    std::vector<Chat*>* chatList;


private:
    AccountDB* accountDB;
    ChatDB* chatDB;
    MessageDB* messageDB;
    QString username;
    int accountId;
};

#endif // CHATCONTROLLER_H
