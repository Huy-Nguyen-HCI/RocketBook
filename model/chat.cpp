#include "chat.h"

Chat::Chat(){

}

Chat::Chat(int chatId)
{
    this->chatId=chatId;


}

Chat::Chat(int chatId, std::vector<int>* memberList){
    this->chatId=chatId;
    this->memberList=memberList;
}


void Chat::addMessage(Message* newMessage){
    messageList.push_back(newMessage);
}

int Chat::getChatId(){
    return chatId;

}

void Chat::setMembers(std::vector<int>* memberList){
    this->memberList=memberList;
}
