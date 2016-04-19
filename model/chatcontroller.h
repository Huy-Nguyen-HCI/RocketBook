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
    ChatController();

    void run();
    int selectChat(QString username);
    void createChat(QString username);
    void addMemberToChat(QString username, int chatId);
    void sendMessage(QString username, int chatId);
    void displayMessages(int chatId);
    void removeUserFromChat(int chatId);
    void deleteMessage(int chatId);


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
};

#endif // CHATCONTROLLER_H
