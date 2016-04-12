#ifndef COMMENT_H
#define COMMENT_H

#include "post.h"

/**
 * @brief The Comment class contains comments which users have posted on blogs.
 */
class Comment: public Post{

public:
    Comment(QString username, QString content);
    Comment(int id, QString username, QString content);
    ~Comment();
private:

};

#endif // COMMENT_H
