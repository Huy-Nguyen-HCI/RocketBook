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
#include "QFile"

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
    /**
     * @brief RocketUser destructor
     */
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
    /**
     * @brief getUsername
     * @return Username of current rocket user
     */
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
    /**
     * @brief changeProfileDescription
     * @param description New profile description
     */
    bool changeProfileDescription(QString description);
    /**
     * @brief changePhoto
     * @param path New profile picture path
     */
    bool changePhoto(QString path);
    /**
     * @brief getChatController
     * @return Chat Controller
     */
    ChatController* getChatController();

    /**
     * @brief Exports scrapbook to HTML
     * @return QString of formatted HTML code containing scrapbook posts, profile picture, profile description, and friends
     */
    QString exportToHtml();

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

    // helper methods for constructing html

    /**
     * @brief Creates HTML code for scrapbook
     * @return QString of formatted HTML code containing scrapbook posts
     */
    QString buildContentHTML();
    /**
     * @brief Creates HTML code for blog post
     * @param *blog specified blog
     * @return QString of formatted HTML code containing blog post
     */
    QString blogToHTML(Blog *blog);
    /**
     * @brief Creates HTML code for tweet post
     * @param *tweet specified tweet
     * @return QString of formatted HTML code containing tweet post
     */
    QString tweetToHTML(Tweet *tweet);
    /**
     * @brief Creates HTML code for multimedia post
     * @param *media specified multimedia
     * @return QString of formatted HTML code containing multimedia post
     */
    QString multimediaToHTML(Multimedia *media);
    /**
     * @brief Creates HTML code for profile
     * @return QString of formatted HTML code containing profile description and profile picture
     */
    QString profileToHTML();
    /**
     * @brief Creates HTML code for friends
     * @return QString of formatted HTML code containing friends list
     */
    QString friendsToHTML();

};

#endif // ROCKETUSER_H
