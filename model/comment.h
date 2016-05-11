#ifndef COMMENT_H
#define COMMENT_H

#include "post.h"

/**
 * @brief The Comment class contains comments which users have posted on blogs.
 */
class Comment: public Post{

public:
    /**
     * @brief Comment constructor for new comment
     * @param username Username
     * @param content Content
     */
    Comment(QString username, QString content);
    /**
     * @brief Comment constructor for comment that already exists
     * @param id Comment Id
     * @param username Username
     * @param content Content
     */
    Comment(int id, QString username, QString content);
    ~Comment();
private:

};

#endif // COMMENT_H
