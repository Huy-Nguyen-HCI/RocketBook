#ifndef CHAT_H
#define CHAT_H

#include <string>
#include <vector>
#include "message.h"

class Chat
{
public:
    Chat(int chatId);
    int getChatId();

    void addMessage(Message* newMessage);


private:
    int chatId;
    std::vector<std::string> memberList;
    std::vector<Message*> messageList;

};

#endif // CHAT_H
