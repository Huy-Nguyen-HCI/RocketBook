#ifndef GROUP_H
#define GROUP_H
#include "profile.h"
#include <vector>
#include <QString>
#include "../database/groupmemberdb.h"
#include "../database/accountdb.h"
#include "../database/profiledb.h"

class Group
{
public:
    /**
     * @brief Group
     * This constructor create a new group
     * @param dbPath The path to database
     * @param groupID The ID of the group
     * @param accountID The account ID of the creator
     * @param fullName Name of group
     * @param photo Photo of group
     * @param description Group description
     */
    Group(QString dbPath,
          int groupID,
          int accountID,
          QString fullName,
          QString photo,
          QString description);

    /**
     * @brief Group
     * This constructor reconstruct an existing group
     * @param dbPath The path to database
     * @param groupID The ID of the group
     * @param profileID The ID of the group profile
     */
    Group(QString dbPath,
          int groupID,
          int profileID);
    /**
     * @brief Group destructor
     */
    ~Group();

    /**
     * @brief getID
     * @return Group Id
     */
    int getID();
    /**
     * @brief getProfile
     * @return Group profile
     */
    Profile* getProfile();

    /**
     * @brief addMember
     * Adds new member to group
     * @param accountId Id of account to be added to group
     * @return True if successful
     */
    bool addMember(int accountID);
    /**
     * @brief addMember
     * Adds new member to group
     * @param username Username of account to be added to group
     * @return True if successful
     */
    bool addMember(QString username);

    /**
     * @brief setAdmin
     * Sets group member as admininstrator of the group
     * @param accountID Account Id of account to be set as admin
     * @return True if successful
     */
    bool setAdmin(int accountID);
    /**
     * @brief setAdmin
     * Sets group member as admininstrator of the group
     * @param username Username of account to be set as admin
     * @return True if successful
     */
    bool setAdmin(QString username);

    /**
     * @brief getMemberNameList
     * Retrieves member name list
     * @return Vector of member names as QStrings
     */
    std::vector<QString> getMemberNameList() { return memberNameList;}
    /**
     * @brief getAdminNameList
     * Retrieves Admin name list
     * @return Vector of admin names as QStrings
     */
    std::vector<QString> getAdminNameList() { return adminNameList;}


private:
    int id;
    static int idCnt;
    QString dbPath;
    Profile* profile;
    std::vector<int> memberIDList;
    std::vector<int> adminIDList;
    std::vector<QString> memberNameList;
    std::vector<QString> adminNameList;
    GroupMemberDB* groupMemberDB;
    AccountDB* accountDB;
    ProfileDB* profileDB;
};

#endif // GROUP_H
