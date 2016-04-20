#ifndef ROCKETUSER_H
#define ROCKETUSER_H
#include "profile.h"
#include <string>
#include <vector>
#include <iostream>
#include "../database/profiledb.h"
#include "../database/frienddb.h"
#include "../database/accountdb.h"
#include "groupcontroller.h"


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

    enum AddFriendStatus { Successful, AlreadyFriend, FriendNotExist, Failed };
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

    /**
     * @brief Sequence of actions for attempting to add friend to user database.
     */
    AddFriendStatus addFriend(QString friendname);
    void deleteFriend(QString friendname);
    QStringList getFriends();
    QStringList getFriendNames();
    std::vector<int> getFriendIds();
    void updateFriendList();

private:
    //Account matters
    AccountDB* accountDB;
    int id;
    static int idCnt;
    QString username;
    int adminRights;

    //Profiles
    Profile* profile;
    ProfileDB* profileDB;

    // friend list
    FriendDB* friendDB;
    std::vector<int> friendIdList;
    QStringList friendNameList;


    //groupList
    GroupController* groupController;

    // feed
    // Chat List




};

#endif // ROCKETUSER_H
