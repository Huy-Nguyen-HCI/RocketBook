#include "groupcontroller.h"

GroupController::GroupController(QString dbPath, int accountID)
{
    this->dbPath = dbPath;
    this->accountID = accountID;

    groupDB = new GroupDB(dbPath);
    groupMemberDB = new GroupMemberDB(dbPath);

    std::vector<int> groupIDList = groupMemberDB->retrieveGroupList(accountID);

    for (unsigned int i = 0; i < groupIDList.size(); i++) {
        int groupID = groupIDList[i];
        int profileID = groupDB->getProfileID(groupID);
        Group* newGroup = new Group(dbPath, groupID, profileID);
        groupList.push_back(newGroup);
    }
}

Group* GroupController::createNewGroup(QString fullName,
                                       QString photo,
                                       QString description)
{
    int groupID = groupDB->getMaxGroupID() + 1;
    Group* newGroup = new Group(dbPath, groupID, accountID, fullName, photo, description);
    groupList.push_back(newGroup);
    groupDB->addGroup(groupID, newGroup->getProfile()->getID());
    return newGroup;
}

std::vector<Group*> GroupController::getAllGroups() {
    return groupList;
}
