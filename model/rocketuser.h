#ifndef ROCKETUSER_H
#define ROCKETUSER_H
#include "profile.h"
#include <string>
#include <vector>


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

private:
    Profile profile;
    // group list
    std::string password;
    // privacy settings
    int adminRights;
    // friend list
    // feed
    // chat container
};

#endif // ROCKETUSER_H
