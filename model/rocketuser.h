#ifndef ROCKETUSER_H
#define ROCKETUSER_H
#include "profile.h"
#include <string>
#include <vector>
#include <iostream>
#include "../database/profiledb.h"
#include "../database/accountdb.h"
#include "groupcontroller.h"
#include "friendcontroller.h"
#include "chatcontroller.h"
#include "feed.h"


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

//    enum AddFriendStatus { Successful, AlreadyFriend, FriendNotExist, Failed };
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

    /**
     * @brief getID
     * Retrieve the ID of the user
     * @return ID of the user
     */
    int getID() { return id;}

    /**
     * @brief getProfile
     * Access the profile, which contains all about user information and scrapbook
     * @return the user profile
     */
    Profile* getProfile();

    QString getUsername() {return username;}

    /**
     * @brief controlGroup
     * Access group functionality of a user
     * @return a group controller
     */
    GroupController* controlGroup() { return groupController;}

    /**
     * @brief controlFriend
     * Access friend functionality of a user
     * @return a friend controller
     */
    FriendController* controlFriend() { return friendController;}

    Feed* getFeed() { return feed;}

    /**
     * @brief isAdmin
     * Check if the user is an admin
     * @return true if user is an admin, false if not
     */
    bool isAdmin() { return adminRights;}

    bool changeProfileDescription(QString description);
    bool changePhoto(QString path);

    ChatController* getChatController();

    ChatController* controlChat() { return chatController;}

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

    FriendController* friendController;
    GroupController* groupController;
    ChatController* chatController;
    Feed* feed;

    // feed
    // Chat List

};

#endif // ROCKETUSER_H
