#ifndef BLOG_H
#define BLOG_H
#include <vector>
#include "post.h"
#include "comment.h"


/**
 * @brief The Blog class contains text that creator of the blog has posted
 * as well as list comments of other users.
 */

class Blog:public Post
{
public:
    /**
     * @brief Construct a blog post
     * @param username The username of the author of the blog
     * @param title The title of the blog
     * @param content The content of the blog
     */
    Blog(QString username, QString title, QString content);

    /**
     * @brief Construct a blog post
     * @param id The ID of the blog post
     * @param username The username of the author of the blog
     * @param title The title of the blog
     * @param content The content of the blog
     */
    Blog(int id, QString username, QString title, QString content);

    /**
     * @brief Default destructor for blog post
     */
    ~Blog();

    /**
     * @brief addComment Add a new comment to the blog
     * @param newComment The new comment to be added to the blog
     */
    Comment* addComment(Comment* newComment);


    QString getUsername() {return username;}

    /**
     * @brief getTitle gets the title for this blog post
     * @return the title for this blog post
     */
    QString getTitle();

    /**
     * @brief getAllComments retrieves all the comments in the blog post
     * @return all comments on the blog post
     */
    std::vector<Comment*> getAllComments();

    /**
     * @brief editBlog Edit the current content of the blog
     * by delete the old content and add the new content
     * @param newContent The new content to be in the blog
     */
    void editBlog(QString newContent);

private:
    std::vector<Comment*> commentList;
    QString title;
};

#endif // BLOG_H
