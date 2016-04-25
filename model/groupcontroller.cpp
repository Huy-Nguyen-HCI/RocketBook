#include "groupcontroller.h"

GroupController::GroupController(QString dbPath, int accountID)
{
    this->dbPath = dbPath;
    this->accountID = accountID;

    groupDB = new GroupDB(dbPath);
    groupMemberDB = new GroupMemberDB(dbPath);

    refreshGroups();
}

GroupController::~GroupController()
{
    delete groupDB;
    delete groupMemberDB;
    for (unsigned int i = 0; i < groupList.size(); i++) {
        delete groupList[i];
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
    refreshGroups();
    return groupList;
}

Group* GroupController::getGroup(int groupID)
{
    for (unsigned int i = 0; i < groupList.size(); i++) {
        if (groupID == groupList[i]->getID()) {
            return groupList[i];
        }
    }
    return NULL;
}

void GroupController::refreshGroups()
{
    for (unsigned int i = 0; i < groupList.size(); i++) {
        delete groupList[i];
    }
    groupList.clear();

    std::vector<int> groupIDList = groupMemberDB->retrieveGroupList(accountID);

    for (unsigned int i = 0; i < groupIDList.size(); i++) {
        int groupID = groupIDList[i];
        int profileID = groupDB->getProfileID(groupID);
        Group* newGroup = new Group(dbPath, groupID, profileID);
        groupList.push_back(newGroup);
    }
}
