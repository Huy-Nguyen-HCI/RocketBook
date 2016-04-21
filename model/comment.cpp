#include "comment.h"

Comment::Comment(QString username, QString content): Post::Post(username, content)
{
    postType = typeComment;
}

Comment::Comment(int id, QString username, QString content): Post::Post(id, username, content)
{
    postType = typeComment;
}


Comment::~Comment() {

}
