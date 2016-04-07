#include "post.h"

int Post::idCnt = 0;

Post::Post(int accountID, std::string content)
{
    id = idCnt;
    idCnt++;

    this->accountID = accountID;
    this->content = content;

}

int Post::getID() {
    return id;
}

int Post::getAuthorID() {
    return accountID;
}

std::string Post::getContent() {
    return content;
}
