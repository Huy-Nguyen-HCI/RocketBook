#ifndef FRIENDCONTROLLER_H
#define FRIENDCONTROLLER_H
#include "../database/frienddb.h"
#include "../database/accountdb.h"
#include "../database/profiledb.h"
#include <iostream>

/**
 * @brief The FriendController class
 * Control all adding/removing friends functionality
 */
class FriendController
{
public:
    enum AddFriendStatus { AddSuccessful, AlreadyFriend, FriendNotExist, AddFailed };
    enum DeleteFriendStatus {DeleteSuccessful, FriendshipNotExist, DeleteFailed};

    /**
     * @brief FriendController
     * @param dbPath
     * @param accountID
     */
    FriendController(QString dbPath, int accountID);

    /**
     * @brief ~FriendController
     * Default destructor
     */
    ~FriendController();


    /**
     * @brief add Friend
     * @param friendname Name of friend
     * @return status of friend being added
     */
    AddFriendStatus addFriend(QString friendname);
    /**
     * @brief delete Friend
     * @param friendname Name of friend
     * @return status of friend being deleted
     */
    DeleteFriendStatus deleteFriend(QString friendname);
    /**
     * @brief getFriends
     * @return List of friend names
     */
    QStringList getFriendNames();
    /**
     * @brief getFriendsIds
     * @return List friend Ids
     */
    std::vector<int> getFriendIds();
    /**
     * @brief Update Friend List
     * Updates friend list based on database
     */

    void updateFriendList();
    /**
     * @brief get Friend Profile
     * @returns Friend's profile info
     */

    ProfileInfoType getFriendProfile(QString username);

private:
    // friend list
    int accountID;
    QString dbPath;
    FriendDB* friendDB;
    AccountDB* accountDB;
    std::vector<int> friendIdList;
    QStringList friendNameList;
    ProfileDB *profileDB;
};

#endif // FRIENDCONTROLLER_H
