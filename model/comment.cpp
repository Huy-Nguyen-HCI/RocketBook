#include "comment.h"

Comment::Comment(std::string username, std::string content): Post::Post(username, content)
{
}

Comment::Comment(int id, std::string username, std::string content): Post::Post(id, username, content)
{
}


Comment::~Comment() {

}
