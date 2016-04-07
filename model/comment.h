#ifndef COMMENT_H
#define COMMENT_H

#include "post.h"
#include <string>

//class Post;
//class RocketUser;
//class Profile;
//class ScrapBook;
//class Blog;
//class Tweet;
//class Multimedia;

/**
 * @brief The Comment class contains comments which users have posted on blogs.
 */
class Comment: public Post{

public:
    Comment(int accountID, std::string content);
    ~Comment();
private:

};

#endif // COMMENT_H
