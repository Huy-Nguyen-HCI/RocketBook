#include "tweet.h"

Tweet::Tweet(std::string username, std::string content): Post(username, content)
{
}

Tweet::Tweet(int id, std::string username, std::string content): Post(id, username, content)
{
}

Tweet::~Tweet() {

}
