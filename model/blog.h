#ifndef BLOG_H
#define BLOG_H
#include <string>
#include <vector>
#include "post.h"
#include "comment.h"

/**
 * @brief The Blog class contains text that creator of the blog has posted
 * as well as list comments of other users.
 */

class Blog:public Post{


public:
    Blog();

private:
    std::vector<Comment*>* commentList;
    std::string text;


    void addComment(Comment* newComment);
    Comment* getComment(int num);
};

#endif // BLOG_H
