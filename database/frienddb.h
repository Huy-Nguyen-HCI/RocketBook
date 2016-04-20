#ifndef FRIENDDB_H
#define FRIENDDB_H

#include <QString>
#include <QtSql>
#include <QDebug>
#include <vector>

/**
 * @brief The FriendDB class
 * Insert/Delete from a sqlite3 table Friends
 * Column 1: AccountID integer
 * Column 2: FriendID integer
 */
class FriendDB
{
public:
    /**
     * @brief FriendDB
     * Construct a friend database
     */
    FriendDB();

    /**
     * @brief FriendDB
     * Construct a friend database, given the path and the name of the database
     * @param path full path name of the frienddb
     */
    FriendDB(const QString& path);

    /**
     * @brief ~FriendDB
     *
     * Default destructor for friend database
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
     * @brief retrieveAllFriends
     * Retrieve all the ID of friends belonging to one account
     * @param accountId The ID of the friends of an account
     * @return
     */
    std::vector<int> retrieveAllFriends(int accountId);

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

    /**
     * @brief addFriend
     * Adds a new friendship by entering one of two entries into the friends table.
     * Must be called twice to completely remove friendship
     *
     * @param accountID Account ID
     * @param friendID Friend ID
     * @return true if added, false if not added
     */
    bool addFriendBothSides(int accountID, int friendID);

    /**
     * @brief removeFriend
     * Removes a friendship. Must be called twice to completed remove friendship
     *
     * @param username the username of the friend to be removed
     * @return true if succeeded, false if failed
     */
    bool removeFriendBothSides(int accountID, int friendID);
    QString connectionName;
};

#endif // FRIENDDB_H
