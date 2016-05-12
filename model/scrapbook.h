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
    /**
     * @brief Scrapbook
     * @param dbPath Database path
     */
    Scrapbook(QString dbPath);
    /**
     * @brief Scrapbook
     * @param dbPath Database path
     * @param id Scrapbook Id
     */
    Scrapbook(QString dbPath, int id);
    /**
     * @brief Scrapbook destructor
     */
    ~Scrapbook();

    /**
     * @brief getId
     * @return Scrapbook Id
     */
    int getID() { return id;}


    /**
     * @brief addBlog
     * Adds blog to scrapbook
     * @param newBlog New blog to be added to scrapbook
     * @return Newly created blog
     */
    Blog* addBlog(Blog* newBlog);
    /**
     * @brief addBlog
     * Constructs new blog and adds blog to scrapbook
     * @param username Author of blog
     * @param title Title of blog
     * @param content Blog content
     * @param privacy True if post is private
     * @return Newly created blog
     */
    Blog* addBlog(QString username,
                  QString title,
                  QString content,
                  bool privacy);
    /**
     * @brief getAllBlogs
     * @return vector of all Blogs in the scrapbook
     */
    std::vector<Blog*> getAllBlogs();

    /**
     * @brief addTweet
     * Adds tweet to scrapbook
     * @param newTweet New tweet to be added to scrapbook
     * @return Newly created tweet
     */
    Tweet* addTweet(Tweet* newTweet);
    /**
     * @brief addTweet
     * Constructs new tweet and adds tweet to scrapbook
     * @param username Author of tweet
     * @param content Tweet content
     * @param privacy True if post is private
     * @return Newly created tweet
     */
    Tweet* addTweet(QString username,
                    QString content,
                    bool privacy);
    /**
     * @brief getAllTweets
     * @return vector of all Tweets in the scrapbook
     */
    std::vector<Tweet*> getAllTweets();
    /**
     * @brief addMedia
     * Adds multimedia to scrapbook
     * @param newMedia New multimedia to be added to scrapbook
     * @return Newly created multimedia
     */
    Multimedia* addMedia(Multimedia* newMedia);
    /**
     * @brief addMedia
     * Constructs new multimedia and adds mutlimedia to scrapbook
     * @param username Author of multimedia
     * @param title Title of multimedia
     * @param description Description of multimedia
     * @param content Multimedia content
     * @param privacy True if post is private
     * @return Newly created multimedia
     */
    Multimedia* addMedia(QString username,
                         QString title,
                         QString description,
                         QString content,
                         bool privacy);


    /**
     * @brief getAllMedia
     * @return vector of all Multimedia in the scrapbook
     */
    std::vector<Multimedia*> getAllMedia();
    /**
     * @brief getAllPosts
     * @return vector of all posts in the scrapbook
     */
    std::vector<Post*> getAllPosts();
    /**
     * @brief getAllPublicPosts
     * @return vector of all public posts in the scrapbook
     */
    std::vector<Post*> getAllPublicPosts();
    /**
     * @brief getLatestPost
     * @param numberOfPost Number of post to be returned in vector
     * @return vector of posts in the scrapbook
     */
    std::vector<Post*> getLatestPosts(int numberOfPosts);
    /**
     * @brief getBlog
     * @param id Blog Id
     * @return Blog at specified Id
     */
    Blog* getBlog(int id);


private:
    int id;
    static int idCnt;

    /**
     * @brief Calls all container constructing methods
     */
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

    /**
     * @brief Constructs Blog Container
     */
    void constructBlogContainer();
    /**
     * @brief Constructs Tweet Container
     */
    void constructTweetContainer();
    /**
     * @brief Constructs Multimedia Container
     */
    void constructMultimediaContainer();
    /**
     * @brief Constructs Comment Container
     */
    void constructCommentContainer();

    /**
     * @brief comparePost
     * Compares two post
     * @param a Post a
     * @param b Post b
     * @return True if Post a is the same as post b
     */
    static bool comparePost(Post* a, Post* b);


};

#endif // SCRAPBOOK_H
