#include "multimedia.h"

Multimedia::Multimedia(std::string username, std::string title, std::string description, std::string content): Post(username, content)
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
