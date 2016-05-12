#ifndef GROUPCONTROLLER_H
#define GROUPCONTROLLER_H
#include "group.h"
#include "../database/groupdb.h"
#include "../database/groupmemberdb.h"


class GroupController
{
public:
    /**
     * @brief GroupController
     * Constructs Group Controller
     * @param dbPath Database Path
     * @param accountID Id of account
     */
    GroupController(QString dbPath,
                    int accountID);
    /**
     * @brief GroupController destructor
     */
    ~GroupController();
    /**
     * @brief createNewGroup
     * Ceates new Group
     * @param fullName Group Name
     * @param photo Group Photo
     * @param description Group Description
     * @return The group which has just been created
     */
    Group* createNewGroup(QString fullName,
                          QString photo,
                          QString description);
    /**
     * @brief getAllGroups
     * @return Vector containing all the groups the user in participating in
     */
    std::vector<Group*> getAllGroups();

    /**
     * @brief getGroup
     * @param groupID Group Id
     * @return Group at given group Id
     */
    Group* getGroup(int groupID);


    /**
     * @brief Refreshes groups objects to match up with database
     */
    void refreshGroups();

private:
    int accountID;
    QString dbPath;
    GroupDB* groupDB;
    GroupMemberDB* groupMemberDB;
    ProfileDB* profileDB;
    std::vector<Group*> groupList;
};

#endif // GROUPCONTROLLER_H
