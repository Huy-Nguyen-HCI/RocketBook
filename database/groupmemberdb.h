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
     * @brief addGroupMember
     * Adds a new groupMembership by entering two entires into the groupMember table:
     * entry 1: userId and groupMemberId
     * entry 2: groupMember Id and User Id
     *
     * @param groupID Group ID
     * @param accountID GroupMember ID
     * @param groupAdminRights Whether the member is an admin, 0 if false, 1 if true
     * @return true if added, false if not added
     */
    bool addGroupMember(int groupID, int accountID, int groupAdminRights);

    /**
     * @brief groupMembershipExists
     * Check if groupMembership exists, knowing the username
     *
     * @param accountID User account ID
     * @param groupMemberID GroupMember account ID
     * @return true if yes, false if no
     */
    bool groupMemberExists(int accountID, int groupMemberID) const;

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
     * @brief removeAllGroupMembers
     * Remove all groupMembers from the database
     * @return true if succeeded, false if failed
     */
    bool removeAllGroupMembers();


private:


    QString connectionName;
};

#endif // GROUPMEMBERDB_H
