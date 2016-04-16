#ifndef CHAT_H
#define CHAT_H

#include <string>
#include <vector>
#include "message.h"

class Chat
{
public:
    Chat(int chatId);


    std::vector<std::string> memberList;
    std::vector<Message*> messageList;

    int chatId;
    int getChatId();

    void addMessage(Message* newMessage);

};

#endif // CHAT_H
