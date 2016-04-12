#ifndef POST_H
#define POST_H

#include <string>


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
     * @param username The username of the author of the post.
     * @param content The content of the post.
     */
    Post(std::string username, std::string content);

    /**
     * @brief Post is a constructor of a post.
     * @param id The ID of the post
     * @param username The username of the author of the post.
     * @param content The content of the post.
     */
    Post(int id, std::string username, std::string content);

    /**
     * @brief getID returns the ID of the post
     * @return the ID of the post.
     */
    int getID();

    /**
     * @brief getAuthor gets the author of the post.
     * @return the author of the post.
     */
    std::string getAuthorUsername();

    /**
     * @brief getContent gets the content of the post.
     * @return the content of the post.
     */
    std::string getContent();

    void setPrivate();

protected:
    std::string username;
    std::string content;
    int id;
    static int idCnt;
    bool privacy;

};

#endif // POST_H
