#include "comment.h"

Comment::Comment(QString username, QString content): Post::Post(username, content)
{
    postType = typeComment;
}

Comment::Comment(int id, QString username, QString content): Post::Post(id, username, content)
{
    this->id = id;
    idCnt = id + 1;
    postType = typeComment;
}


Comment::~Comment() {

}
