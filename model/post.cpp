#include "post.h"

int Post::idCnt = 0;

Post::Post(std::string username, std::string content)
{
    id = idCnt;
    idCnt++;

    this->username = username;
    this->content = content;
    privacy = 0;

}

Post::Post(int id, std::string username, std::string content)
{
    this->id = id;
    idCnt = id;
    idCnt++;

    this->username = username;
    this->content = content;
    privacy = 0;
}

int Post::getID() {
    return id;
}

std::string Post::getAuthorUsername() {
    return username;
}

std::string Post::getContent() {
    return content;
}

void Post::setPrivate() {
    privacy = 1;
}
