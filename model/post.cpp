#include "post.h"

int Post::idCnt = 0;

Post::Post(std::string username, std::string content)
{
    id = idCnt;
    idCnt++;

    this->username = username;
    this->content = content;

}

Post::Post(int id, std::__cxx11::string username, std::__cxx11::string content)
{
    this->id = id;
    idCnt = id;
    idCnt++;

    this->username = username;
    this->content = content;

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
