#ifndef SCRAPBOOK_H
#define SCRAPBOOK_H

#include "blog.h"
#include "tweet.h"
#include "multimedia.h"
#include "comment.h"

#include "../database/blogdb.h"
#include "../database/tweetdb.h"
#include "../database/multimediadb.h"
#include "../database/commentdb.h"
#include "../database/accountdb.h"


/**
 * @brief The Scrapbook class
 * Contains all the content a user has posted.
 */

class Scrapbook
{
public:
    Scrapbook();
    Scrapbook(int id);
    ~Scrapbook();

    int getID() { return id;}


    //Methods for add to and getting from containers
    Blog* addBlog(Blog* newBlog);
    Blog* addBlog(QString username,
                  QString title,
                  QString content,
                  bool privacy);

    Tweet* addTweet(Tweet* newTweet);
    Tweet* addTweet(QString username,
                    QString content,
                    bool privacy);

    Multimedia* addMedia(Multimedia* newMedia);
    Multimedia* addMedia(QString username,
                         QString title,
                         QString description,
                         QString content,
                         bool privacy);

private:
    int id;
    static int idCnt;

    //Methods for constructing all containers from database
    void constructContentContainers();

    BlogDB* blogDB;
    TweetDB* tweetDB;
    MultimediaDB* multimediaDB;
    CommentDB* commentDB;
    AccountDB* accountDB;

    std::vector<Blog*> blogList;
    std::vector<Tweet*> tweetList;
    std::vector<Multimedia*> mediaList;
    std::vector<Post*> postList;



//    Blog* getBlog(int num);
//    Tweet* getTweet(int num);
//    Multimedia* getMedia(int num);

};

#endif // SCRAPBOOK_H
