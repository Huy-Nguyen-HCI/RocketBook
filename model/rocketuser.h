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
    RocketUser(int id)
    {
    } ///This is here for now, because I can't code any more, but we'll take it out

    /**
     * @brief RocketUser
     * Used to create a new account, must have full name, photo, description, etc.
     * @param fullName
     * @param photo
     * @param description
     */
    RocketUser(QString username,
               QString fullName = "",
               QString photo = "",
               QString description = "",
               int adminRights = 0);

    /**
     * @brief RocketUser
     * Only used for login, reconstruct everything
     * @param id
     * @param username
     * @param profileID
     * @param adminRights
     */
    RocketUser(int id,
               QString username,
               int profileID,
               int adminRights);

    ~RocketUser();
    int getID();
    Profile* getProfile();
    bool isAdmin() { return adminRights;}

private:
    Profile* profile;
    int id;
    static int idCnt;
    QString username;
    ProfileDB* profileDB;
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
