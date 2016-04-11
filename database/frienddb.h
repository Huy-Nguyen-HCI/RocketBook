#ifndef FRIENDDB_H
#define FRIENDDB_H

#include <QString>
#include <QtSql>
#include <QDebug>

class FriendDB
{
public:
    FriendDB();

    /**
     * @brief FriendDB
     * Construct an account database, given the path and the name of the database
     * @param path full path name of the accountdb
     */
    FriendDB(const QString& path);

    /**
     * @brief ~FriendDB
     *
     * Default destructor for account database
     */
    ~FriendDB();

    /**
     * @brief isOpen
     *
     * Check whether account database is open
     * @return true if yes, false if no
     */
    bool isOpen() const;

    /**
     * @brief addFriend
     * Adds a new friendship by entering two entires into the friend table:
     * entry 1: userId and friendId
     * entry 2: friend Id and User Id
     *
     * @param accountID Account ID
     * @param friendID Friend ID
     * @return true if added, false if not added
     */
    bool addFriend(int accountID, int friendID);

    /**
     * @brief removeFriend
     * Remove a friendship
     *
     * @param username the username of the friend to be removed
     * @return true if succeeded, false if failed
     */
    bool removeFriend(int accountID, int friendID);

    /**
     * @brief retrieveAccountInfo
     * Return a string including ID's of all of the accounts which the user is friends with
     *
     * @param  accountID User's account Id.
     * @param password password of the account
     * @return a string with all friend account Ids.
     */

    QString retrieveAllFriends(int accountId);

    /**
     * @brief friendshipExists
     * Check if friendship exists, knowing the username
     *
     * @param accountID User account ID
     * @param friendID Friend account ID
     * @return true if yes, false if no
     */
    bool friendshipExists(int accountID, int friendID) const;

    /**
     * @brief removeAllFriends
     * Remove all friends from the database
     * @return true if succeeded, false if failed
     */
    bool removeAllFriends();


private:

    bool addFriendBothSides(int accountID, int friendID);
    bool removeFriendBothSides(int accountID, int friendID);
    QString connectionName;
};

#endif // FRIENDDB_H
