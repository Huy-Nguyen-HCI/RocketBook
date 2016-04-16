#include "chat.h"

Chat::Chat(int chatId)
{
    this->chatId=chatId;


}


void Chat::addMessage(Message* newMessage){
    messageList.push_back(newMessage);
}

int Chat::getChatId(){
    return chatId;

}
