#ifndef POST_H
#define POST_H

#include <string>
//#include <rocketuser.h>

//class RocketUser;
//class Profile;
//class ScrapBook;
//class Blog;
//class Comment;
//class Tweet;
//class Multimedia;

/**
 * @brief The Post class serves as a parent for all content that the user can post
 *        Types of posts:
 *          Blog
 *          Multimedia
 *          Tweet
 *          Comment
 */
class Post
{
public:
    /**
     * @brief Post is a constructor of a post.
     *
     * @param author The pointer to the author of the post.
     * @param content The content of the post.
     */
    Post(int accountID, std::string content);

    /**
     * @brief getID returns the ID of the post
     * @return the ID of the post.
     */
    int getID();

    /**
     * @brief getAuthor gets the author of the post.
     * @return the author of the post.
     */
    int getAuthorID();

    /**
     * @brief getContent gets the content of the post.
     * @return the content of the post.
     */
    std::string getContent();

protected:
    int accountID;
    std::string content;
    int id;
    static int idCnt;

};

#endif // POST_H
