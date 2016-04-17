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
    void selectChat();
    void createChat();
    void addMemberToChat();


    int requestInput();
    int requestInput2();
    std::string askUserName();



private:
    AccountDB* accountDB;
    FriendDB* friendDB;
    ChatDB* chatDB;
    MessageDB* messageDB;
};

#endif // CHATCONTROLLER_H
