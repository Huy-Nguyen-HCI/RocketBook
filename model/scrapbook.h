#ifndef SCRAPBOOK_H
#define SCRAPBOOK_H

#include "blog.h"
#include "tweet.h"
#include "multimedia.h"


/**
 * @brief The Scrapbook class contains all the content a user has posted.
 */

class Scrapbook
{
public:
    Scrapbook();
    Scrapbook(int id);

private:
    int id;
    static int idCnt;

    std::vector<Blog*> blogList;
    std::vector<Tweet*> tweetList;
    std::vector<Multimedia*> mediaList;
    std::vector<Post*> postList;

    //Methods for add to and getting from containers
    void addBlog(Blog* newBlog);
    void addTweet(Tweet* newTweet);
    void addMedia(Multimedia* newMedia);

//    Blog* getBlog(int num);
//    Tweet* getTweet(int num);
//    Multimedia* getMedia(int num);

};

#endif // SCRAPBOOK_H
