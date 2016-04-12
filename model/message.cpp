#include "message.h"

Message::Message()
{

}

Message::Message(int timeId, std::string senderName, std::string text){
    this->timeId=timeId;
    this->senderName=senderName;
    this->text=text;
}

Message::~Message(){

}
