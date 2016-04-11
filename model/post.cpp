#include "post.h"

int Post::idCnt = 0;

Post::Post(std::__cxx11::string username, std::string content)
{
    id = idCnt;
    idCnt++;

    this->username = username;
    this->content = content;

}

int Post::getID() {
    return id;
}

int Post::getAuthorUsername() {
    return username;
}

std::string Post::getContent() {
    return content;
}
