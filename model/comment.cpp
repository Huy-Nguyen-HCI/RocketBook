#include "comment.h"

Comment::Comment(QString username, QString content): Post::Post(username, content)
{
}

Comment::Comment(int id, QString username, QString content): Post::Post(id, username, content)
{
}


Comment::~Comment() {

}
