#include "tweet.h"

Tweet::Tweet(QString username, QString content): Post(username, content)
{
}

Tweet::Tweet(int id, QString username, QString content): Post(id, username, content)
{
}

Tweet::~Tweet() {

}
