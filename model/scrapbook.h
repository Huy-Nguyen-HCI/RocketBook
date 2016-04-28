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
    Scrapbook(QString dbPath);
    Scrapbook(QString dbPath, int id);
    ~Scrapbook();

    int getID() { return id;}


    //Methods for add to and getting from containers
    Blog* addBlog(Blog* newBlog);
    Blog* addBlog(QString username,
                  QString title,
                  QString content,
                  bool privacy);
    std::vector<Blog*> getAllBlogs();

//    /**
//     * @brief addComment
//     * Add a new comment to the blog
//     * @param username The username of the commenter
//     * @param content The content of the comment
//     * @return the actual comment
//     */
//    Comment* addComment(int blogID, QString username, QString content);

    Tweet* addTweet(Tweet* newTweet);
    Tweet* addTweet(QString username,
                    QString content,
                    bool privacy);

    std::vector<Tweet*> getAllTweets();

    Multimedia* addMedia(Multimedia* newMedia);
    Multimedia* addMedia(QString username,
                         QString title,
                         QString description,
                         QString content,
                         bool privacy);
    std::vector<Multimedia*> getAllMedia();

    std::vector<Post*> getAllPosts();
    std::vector<Post*> getAllPublicPosts();
    std::vector<Post*> getLatestPosts(int numberOfPosts);

    Blog* getBlog(int id);
    //    Tweet* getTweet(int num);
    //    Multimedia* getMedia(int num);

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
    QString dbPath;

    std::vector<Blog*> blogList;
    std::vector<Tweet*> tweetList;
    std::vector<Multimedia*> mediaList;
    std::vector<Post*> postList;
    std::vector<Post*> publicPostList;

    void constructBlogContainer();
    void constructTweetContainer();
    void constructMultimediaContainer();
    void constructCommentContainer();

    static bool comparePost(Post* a, Post* b);




};

#endif // SCRAPBOOK_H
