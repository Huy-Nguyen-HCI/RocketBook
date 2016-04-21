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
     * @param accountID
     */
    FriendController(QString dbPath, int accountID);

    AddFriendStatus addFriend(QString friendname);
    DeleteFriendStatus deleteFriend(QString friendname);
    QStringList getFriends();
    QStringList getFriendNames();
    std::vector<int> getFriendIds();
    void updateFriendList();
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
