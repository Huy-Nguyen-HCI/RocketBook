#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>


class Message
{
public:
    Message();
    Message(int timeId, std::string senderName, std::string text);
    ~Message();

    int timeId;
    std::string senderName;
    std::string text;


};

#endif // MESSAGE_H
