#ifndef TWEET_H
#define TWEET_H

#include <string>
#include "post.h"

/**
 * @brief The Tweet class is a post which contains a string of 140 characters or less
 */

class Tweet:public Post{

public:
    Tweet();

private:
    std::string content;
    //char[140] content;
};

#endif // TWEET_H
