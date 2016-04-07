#ifndef BLOG_H
#define BLOG_H
#include <string>
#include <vector>
#include "post.h"
#include "comment.h"

//class Post;
//class RocketUser;
//class Profile;
//class ScrapBook;
//class Tweet;
//class Multimedia;
//class Comment;

/**
 * @brief The Blog class contains text that creator of the blog has posted
 * as well as list comments of other users.
 */

class Blog:public Post
{
public:
    /**
     * @brief Construct a blog post
     * @param author Pointer to the author of the blog
     * @param title The title of the blog
     * @param content The content of the blog
     */
    Blog(int accountID, std::string title, std::string content);

    /**
     * @brief Default destructor for blog post
     */
    ~Blog();

    /**
     * @brief addComment Add a new comment to the blog
     * @param newComment The new comment to be added to the blog
     */
    void addComment(Comment* newComment);

    /**
     * @brief getTitle gets the title for this blog post
     * @return the title for this blog post
     */
    std::string getTitle();

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
    void editBlog(std::string newContent);

private:
    std::vector<Comment*> commentList;
    std::string title;
};

#endif // BLOG_H
