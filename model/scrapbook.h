#ifndef SCRAPBOOK_H
#define SCRAPBOOK_H

#include "blog.h"
#include "tweet.h"
#include "multimediacontent.h"
#include "post.h"

/**
 * @brief The Scrapbook class contains all the content a user has posted.
 */

class ScrapBook
{
public:
    ScrapBook();

private:
    std::vector<Blog*>* blogList;
    std::vector<Tweet*>* tweetList;
    std::vector<MultimediaContent*>* mediaList;

    void addBlog(Blog* newBlog);
    Blog* getBlog(int num);
    void addTweet(Tweet* newTweet);
    Tweet* getTweet(int num);
    void addMedia(MultimediaContent* newMedia);
    MultimediaContent* getMedia(int num);

};

#endif // SCRAPBOOK_H
