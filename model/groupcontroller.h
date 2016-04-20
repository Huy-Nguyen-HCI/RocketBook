#ifndef GROUPCONTROLLER_H
#define GROUPCONTROLLER_H
#include "group.h"
#include "../database/groupdb.h"
#include "../database/groupmemberdb.h"


class GroupController
{
public:
    GroupController(QString dbPath,
                    int accountID);

    Group* createNewGroup(QString fullName,
                          QString photo,
                          QString description);

    std::vector<Group*> getAllGroups();

private:
    int accountID;
    QString dbPath;
    GroupDB* groupDB;
    GroupMemberDB* groupMemberDB;
    ProfileDB* profileDB;
    std::vector<Group*> groupList;
};

#endif // GROUPCONTROLLER_H
