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

    ~Group();

    int getID();
    Profile* getProfile();

    //add a new member
    bool addMember(int accountID);
    bool addMember(QString username);

    //set a member to be admin
    bool setAdmin(int accountID);
    bool setAdmin(QString username);

    //retrieve member name list
    std::vector<QString> getMemberNameList() { return memberNameList;}
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
