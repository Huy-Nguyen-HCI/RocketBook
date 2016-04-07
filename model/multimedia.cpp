#include "multimedia.h"

Multimedia::Multimedia(int accountID, std::string title, std::string description, std::string content): Post(accountID, content)
{
    this->title = title;
    this->description = description;

}

Multimedia::~Multimedia() {

}

std::string Multimedia::getTitle() {
    return title;
}

std::string Multimedia::getDescription() {
    return description;
}
