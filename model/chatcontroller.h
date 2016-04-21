#ifndef CHATCONTROLLER_H
#define CHATCONTROLLER_H

#include <iostream>
#include <sstream>
#include <QDebug>
#include <QCoreApplication>
#include "../database/chatdb.h"
#include "../database/messagedb.h"
#include "../database/accountdb.h"
#include "../database/frienddb.h"
#include <string>
#include "rocketuser.h"
#include "chat.h"
#include "message.h"



class ChatController
{
public:
    ChatController(QString username);

    void run();
    int selectChat();   /**< used in terminal */
    void createChat();
    void addMemberToChat(int chatId);   /**< user in terminal */
    void sendMessage(int chatId);
    void displayMessages(int chatId);
    void removeUserFromChat(int chatId);    /**< used in terminal */
    void deleteMessage(int chatId);
    std::vector<int>* getChatIdList();
    std::vector<int>* getSenderList(int chatId);
    std::vector<QString>* getMessageList(int chatId);


    int requestInput();
    int requestInput2();
    int userPicksChat();
    std::string userEntersMessage();
    std::string askUserName();



private:
    AccountDB* accountDB;
    FriendDB* friendDB;
    ChatDB* chatDB;
    MessageDB* messageDB;
    QString username;
};

#endif // CHATCONTROLLER_H
