#ifndef SCRAPBOOK_H
#define SCRAPBOOK_H

#include "blog.h"
#include "tweet.h"
#include "multimedia.h"

//class Blog;
//class Post;
//class RocketUser;
//class Profile;
//class Comment;
//class Tweet;
//class Multimedia;

/**
 * @brief The Scrapbook class contains all the content a user has posted.
 */

class ScrapBook
{
public:
    ScrapBook();

private:
    std::vector<Blog*> blogList;
    std::vector<Tweet*> tweetList;
    std::vector<Multimedia*> mediaList;

    //Methods for add to and getting from containers
    void addBlog(Blog* newBlog);
    void addTweet(Tweet* newTweet);
    void addMedia(Multimedia* newMedia);

//    Blog* getBlog(int num);
//    Tweet* getTweet(int num);
//    Multimedia* getMedia(int num);

};

#endif // SCRAPBOOK_H
