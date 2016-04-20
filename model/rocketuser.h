#ifndef ROCKETUSER_H
#define ROCKETUSER_H
#include "profile.h"
#include <string>
#include <vector>
#include <iostream>
#include "../database/profiledb.h"
#include "../database/frienddb.h"
#include "../database/accountdb.h"


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

    /**
     * @brief RocketUser
     * Used to create a new account, must have full name, photo, description, etc.
     * @param fullName
     * @param photo
     * @param description
     */
    RocketUser(QString dbPath,
               int id,
               QString username,
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
    RocketUser(QString dbPath,
               int id,
               QString username,
               int profileID,
               int adminRights);

    ~RocketUser();
    int getID();
    Profile* getProfile();
    bool isAdmin() { return adminRights;}
    void generateFriendList();

    /**
     * @brief Sequence of actions for attempting to add friend to user database.
     */
    void addFriend(QString friendname);

    void deleteFriend(QString friendname);

    std::vector<QString> getFriendNames();
    std::vector<int> getFriendIds();

    void updateFriendList();

private:
    Profile* profile;
    int id;
    static int idCnt;
    QString username;
    ProfileDB* profileDB;
    AccountDB* accountDB;
    // group list
    // privacy settings
    int adminRights;
    // friend list


    // feed
  // Chat List
    std::vector<int> friendIdList;
    std::vector<QString> friendNameList;


   FriendDB* friendDB;

};

#endif // ROCKETUSER_H
