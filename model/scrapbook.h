#ifndef SCRAPBOOK_H
#define SCRAPBOOK_H

#include "blog.h"
#include "tweet.h"
#include "multimedia.h"
#include "../database/blogdb.h"
#include "../database/tweetdb.h"
#include "../database/multimediadb.h"


/**
 * @brief The Scrapbook class contains all the content a user has posted.
 */

class Scrapbook
{
public:
    Scrapbook();
    Scrapbook(int id);

    //Methods for add to and getting from containers
    Blog* addBlog(Blog* newBlog);
    Blog* addBlog(std::string username, std::string title, std::string content);

    Tweet* addTweet(Tweet* newTweet);
    Tweet* addTweet(std::string username, std::string content);

    Multimedia* addMedia(Multimedia* newMedia);
    Multimedia* addMedia(std::string username,
                         std::string title,
                         std::string description,
                         std::string content);

private:
    int id;
    static int idCnt;

    BlogDB* blogDB;
    TweetDB* tweetDB;
    MultimediaDB* multimediaDB;

    std::vector<Blog*> blogList;
    std::vector<Tweet*> tweetList;
    std::vector<Multimedia*> mediaList;
    std::vector<Post*> postList;



//    Blog* getBlog(int num);
//    Tweet* getTweet(int num);
//    Multimedia* getMedia(int num);

};

#endif // SCRAPBOOK_H
