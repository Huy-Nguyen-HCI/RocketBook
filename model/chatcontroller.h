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


    int requestInput();
    std::string askUserName();



private:
    AccountDB* accountDB;
    ChatDB* chatDB;
    MessageDB* messageDB;
};

#endif // CHATCONTROLLER_H
