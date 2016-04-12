#include "post.h"

int Post::idCnt = 0;

Post::Post(QString username, QString content)
{
    id = idCnt;
    idCnt++;

    this->username = username;
    this->content = content;
    privacy = 0;

}

Post::Post(int id, QString username, QString content)
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

QString Post::getAuthorUsername() {
    return username;
}

QString Post::getContent() {
    return content;
}

void Post::setPrivate() {
    privacy = 1;
}
