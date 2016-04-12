#ifndef TWEET_H
#define TWEET_H

#include <string>
#include "post.h"

//class Post;
//class RocketUser;
//class Profile;
//class Scrapbook;
//class Blog;
//class Comment;
//class Multimedia;

/**
 * @brief The Tweet class is a post which contains a string of 140 characters or less
 */
class Tweet: public Post
{
public:
    Tweet(QString username, QString content);
    Tweet(int id, QString username, QString content);
    ~Tweet();

private:

};

#endif // TWEET_H
