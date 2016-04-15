#ifndef ROCKETUSER_H
#define ROCKETUSER_H
#include "profile.h"
#include <string>
#include <vector>
#include "../database/profiledb.h"

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
    RocketUser(); ///This is here for now, because I can't code any more, but we'll take it out

    /**
     * @brief RocketUser
     *
     * @param fullName
     * @param photo
     * @param description
     */
    RocketUser(QString fullName, QString photo, QString description);
    RocketUser(int id);
    ~RocketUser();
    int getID();
    Profile* getProfile();

private:
    Profile* profile;
    int id;
    static int idCnt;

    // group list
    std::string password;
    // privacy settings
    int adminRights;
    // friend list
    std::vector<int>* friendList;
    void addFriend(int friendUserId);
    // feed
  // Chat List


};

#endif // ROCKETUSER_H
