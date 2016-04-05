#ifndef COMMENT_H
#define COMMENT_H

#include "post.h"
#include <string>

/**
 * @brief The Comment class contains comments which users have posted on blogs.
 */

class Comment:public Post{

public:
    Comment();

private:
    std::string content;

};

#endif // COMMENT_H
