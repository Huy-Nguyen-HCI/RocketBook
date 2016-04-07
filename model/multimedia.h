#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <post.h>

//class Post;
//class RocketUser;
//class Profile;
//class ScrapBook;
//class Blog;
//class Comment;
//class Tweet;



/**
 * @brief The Multimedia Class holds multimedia content which the user has posted.
 */

class Multimedia:public Post{


public:
    Multimedia(int accountID, std::string title, std::string description, std::string content);
    ~Multimedia();
    std::string getTitle();
    std::string getDescription();

private:
    std::string title;
    std::string description;
};

#endif // MULTIMEDIA_H
