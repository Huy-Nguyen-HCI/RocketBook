#ifndef TWEET_H
#define TWEET_H

#include <string>
#include "post.h"

/**
 * @brief The Tweet class is a post which contains a string of 140 characters or less
 */
class Tweet: public Post
{
public:
    /**
     * @brief Tweet constructor for new tweet
     * @param username Author of tweet
     * @param content Tweet content
     */
    Tweet(QString username, QString content);
    /**
     * @brief Tweet constructor for existing tweet
     * @param id Post Id
     * @param username Author of tweet
     * @param content Tweet content
     */
    Tweet(int id, QString username, QString content);
    /**
     * @brief Tweet destructor
     */
    ~Tweet();

private:

};

#endif // TWEET_H
