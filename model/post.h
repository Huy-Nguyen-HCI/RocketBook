#ifndef POST_H
#define POST_H

#include <string>

/**
 * @brief The Post class serves as a parent for all content that the user can post
 *        Types of posts:
 *          Blog
 *          Multimedia Content
 *          Tweet
 *          Comment
 */

class Post
{
public:
    Post();

protected:
    std::string username;

};

#endif // POST_H
