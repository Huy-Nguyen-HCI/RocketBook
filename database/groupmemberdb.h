#ifndef GROUPMEMBERDB_H
#define GROUPMEMBERDB_H

#include <QString>
#include <QtSql>
#include <QDebug>
#include <vector>

typedef std::tuple<int, int, int> GroupMemberInfoType;

/**
 * @brief The GroupMemberDB class
 *
 * Insert/Delete from a sqlite3 table GroupMembers
 * Column 1: GroupID INTEGER NOT NULL
 * Column 2: FriendID INTEGER NOT NULL
 * Column 3: GroupAdminRights INTEGER NOT NULL
 */
class GroupMemberDB
{
public:
    /**
     * @brief GroupMemberDB
     * Construct a group member database
     */
    GroupMemberDB();
    /**
     * @brief GroupMemberDB
     * Construct a group members database, given the path and the name of the database
     * @param path full path name of the groupMemberdb
     */
    GroupMemberDB(const QString& path);

    /**
     * @brief GroupMemberDB
     * @param path
     * @param connectionName
     */
    GroupMemberDB(const QString &path, const QString &connectionName);

    /**
     * @brief ~GroupMemberDB
     *
     * Default destructor for groupMember database
     */
    ~GroupMemberDB();

    /**
     * @brief isOpen
     *
     * Check whether account database is open
     * @return true if yes, false if no
     */
    bool isOpen() const;

    /**
     * @brief createGroup
     * Create a new group with only one member in which the member is an admin.
     * @param groupID The ID of the group to be created
     * @param accountID The ID of the account
     * @return true if created, false if not
     */
    bool createGroup(int groupID, int accountID);

    /**
     * @brief addGroupMember
     * Adds a new groupMembership by entering two entires into the groupMember table:
     * entry 1: userId and groupMemberId
     * entry 2: groupMember Id and User Id
     *
     * @param groupID Group ID
     * @param accountID GroupMember ID
     * @param groupAdminRights Whether the member is an admin, 0 if false, 1 if true. Default is 0
     * @return true if added, false if not added
     */
    bool addGroupMember(int groupID, int accountID, int groupAdminRights = 0);

    /**
     * @brief groupMembershipExists
     * Check if groupMembership exists, knowing the username
     *
     * @param accountID User account ID
     * @param groupMemberID GroupMember account ID
     * @return true if yes, false if no
     */
    bool groupMemberExists(int groupID, int accountID) const;

    /**
     * @brief removeGroupMember
     * Remove a groupMembership
     *
     * @param groupID The Group ID of the group in which a member got removed
     * @param accountID The Account ID to be removed
     * @return true if succeeded, false if failed
     */
    bool removeGroupMember(int groupID, int accountID);

    /**
     * @brief retrieveAllGroupMembersInfo
     * Retrieve all group members from one group
     * @param groupID The ID of the group
     * @return a vector of all member info, including ID and the admin rights
     */
    std::vector<GroupMemberInfoType> retrieveAllGroupMembersInfo(int groupID);

    /**
     * @brief retrieveGroupList
     * Retrieve the group list in one account
     * @param accountID
     * The ID of the account
     * @return the list of group IDs
     */
    std::vector<int> retrieveGroupList(int accountID);

    /**
     * @brief removeAllGroupMembers
     * Remove all groupMembers from the database
     * @return true if succeeded, false if failed
     */
    bool removeAllGroupMembers();

    /**
     * @brief getMaxGroupID
     * Retrieve the last group ID
     * @return the max (last) group ID
     */
    int getMaxGroupID();

    /**
     * @brief setAdmin
     * Set a group member to become admin
     * @param groupID
     * @param accountID
     * @return true if succeeded, false if failed
     */
    bool setAdmin(int groupID, int accountID);


private:


    QString connectionName;
};

#endif // GROUPMEMBERDB_H
