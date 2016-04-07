#ifndef ROCKETUSER_H
#define ROCKETUSER_H
#include "profile.h"
#include <string>
#include <vector>

//class Profile;
//class ScrapBook;
//class Blog;
//class Post;
//class Comment;
//class Tweet;
//class Multimedia;

/**
 * @brief The RocketUser class stores information about the user.
 *      Profile
 *      Group list
 *      Password
 *      Privacy settings
 *      Admin rights
 *      Friend list
 *      Feed
 *      Chat container
 */
class RocketUser
{
public:
    RocketUser();
    RocketUser(int id);
    ~RocketUser();
    int getID();
    Profile* getProfile();

private:
    Profile* profile;
    int id;
    // group list
    std::string password;
    // privacy settings
    int adminRights;
    // friend list
    std::vector<int>* friendList;
    void addFriend(int friendUserId);
    // feed
    // chat container
    static int idCnt;

};

#endif // ROCKETUSER_H
