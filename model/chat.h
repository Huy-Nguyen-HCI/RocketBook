#ifndef CHAT_H
#define CHAT_H

#include <string>
#include <vector>
#include "message.h"

class Chat
{
public:
    Chat();
    Chat(int chatId);
    Chat(int chatId, std::vector<int>* memberList);
    int getChatId();

    void addMessage(Message* newMessage);
    void addMember();
    void setMembers(std::vector<int>* memberList);


private:
    int chatId;
    std::vector<int>* memberList;
    std::vector<Message*> messageList;

};

#endif // CHAT_H
