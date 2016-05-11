#ifndef CHAT_H
#define CHAT_H

#include <string>
#include <vector>
#include "message.h"

/**
 * @brief The chat class contains a list of messages and a list of participants in a given chat.
 */


class Chat
{
public:

    /**
     * @brief Chat Constructor
     */
    Chat();
    /**
     * @brief Chat Constructor
     * @param chatId Chat Id
     */
    Chat(int chatId);
    /**
     * @brief Chat Constructor
     * @param chatId Chat Id
     * @param memberList List of chat participants
     */
    Chat(int chatId, std::vector<int>* memberList);
    /**
     * @brief getChatId
     * @return Chat Id
     */
    int getChatId();
    /**
     * @brief Adds a message to chat
     * @param newMessage Message to be added
     */
    void addMessage(Message* newMessage);
    /**
     * @brief set chat members
     * @param memberList List of members
     */
    void setMembers(std::vector<int>* memberList);


private:
    int chatId;
    std::vector<int>* memberList;
    std::vector<Message*> messageList;

};

#endif // CHAT_H
