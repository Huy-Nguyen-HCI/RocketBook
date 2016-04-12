#include "chat.h"

Chat::Chat()
{

}


void Chat::addMessage(Message* newMessage){
    messageList.push_back(newMessage);
}
