#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

/**
 * @brief The message class includes a text message and the sender of this message
 */


class Message
{
public:
    /**
     * @brief Message
     * Constructs message
     */

    Message();
    /**
     * @brief Message
     * Constructs message
     * @param timeId Time Id
     * @param senderName Name of sender
     * @param text Message contents
     */
    Message(int timeId, std::string senderName, std::string text);
    /**
     * @brief ~Message
     * Destructs message
     */
    ~Message();

    int timeId;
    std::string senderName;
    std::string text;


};

#endif // MESSAGE_H
