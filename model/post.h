#ifndef POST_H
#define POST_H

#include <QString>


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
    Post(QString username, QString content);

    /**
     * @brief Post is a constructor of a post.
     * @param id The ID of the post
     * @param username The username of the author of the post.
     * @param content The content of the post.
     */
    Post(int id, QString username, QString content);

    /**
     * @brief getID returns the ID of the post
     * @return the ID of the post.
     */
    int getID();

    /**
     * @brief getAuthor gets the author of the post.
     * @return the author of the post.
     */
    QString getAuthorUsername();

    /**
     * @brief getContent gets the content of the post.
     * @return the content of the post.
     */
    QString getContent();

    void setPrivate();

    bool getPrivacy() {return privacy;}

protected:
    QString username;
    QString content;
    int id;
    static int idCnt;
    bool privacy;

};

#endif // POST_H
