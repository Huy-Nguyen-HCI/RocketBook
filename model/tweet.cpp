#include "tweet.h"

Tweet::Tweet(QString username, QString content): Post(username, content)
{
    postType = typeTweet;
}

Tweet::Tweet(int id, QString username, QString content): Post(id, username, content)
{
    postType = typeTweet;
}

Tweet::~Tweet() {

}
