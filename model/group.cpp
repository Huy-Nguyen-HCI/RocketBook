#include "group.h"

int Group::idCnt = 0;

Group::Group(QString dbPath,
             int groupID,
             int accountID,
             QString fullName,
             QString photo,
             QString description)
{
    this->id = groupID;
    idCnt = id;
    idCnt++;

    this->dbPath = dbPath;

    //add a new profile
    profileDB = new ProfileDB(dbPath, "ProfileGroup");
    profile = new Profile(dbPath, fullName, photo, description);
    profileDB->addProfile(profile->getID(),
                          fullName,
                          photo,
                          description,
                          profile->getScrapbook()->getID());

    //add the only admin
    accountDB = new AccountDB(dbPath, "accountGroup");
    groupMemberDB = new GroupMemberDB(dbPath, "groupMemberGroup");
    groupMemberDB->addGroupMember(groupID, accountID, 1);
    adminIDList.push_back(accountID);
    adminNameList.push_back(accountDB->getUsername(accountID));

}

Group::Group(QString dbPath,
             int groupID,
             int profileID)
{
    this->id = groupID;
    idCnt = id;
    idCnt++;

    this->dbPath = dbPath;

    //retrieve group members
    accountDB = new AccountDB(dbPath, "accountGroup");
    groupMemberDB = new GroupMemberDB(dbPath, "groupMemberGroup");
    std::vector<GroupMemberInfoType> groupMemberInfo = groupMemberDB->retrieveAllGroupMembersInfo(id);
    for (unsigned int i = 0; i < groupMemberInfo.size(); i++) {
        int accountID = std::get<1>(groupMemberInfo[i]);
        int adminRights = std::get<2>(groupMemberInfo[i]);
        QString username = accountDB->getUsername(accountID);
        if (adminRights) {
            adminIDList.push_back(accountID);
            adminNameList.push_back(username);
        } else {
            memberIDList.push_back(accountID);
            memberNameList.push_back(username);
        }
    }

    // retrieve profile
    profileDB = new ProfileDB(dbPath, "ProfileGroup");
    if (profileDB->profileExists(profileID)) {
        ProfileInfoType profileInfo = profileDB->retrieveProfileInfo(profileID);
        QString fullName = std::get<1>(profileInfo);
        QString photo = std::get<2>(profileInfo);
        QString description = std::get<3>(profileInfo);
        int scrapbookID = std::get<4>(profileInfo);
        profile = new Profile(dbPath, profileID, fullName, photo, description, scrapbookID);
    } else {
        //qDebug() << "Profile does not exists.";
    }

}

Group::~Group()
{
    delete profile;
    delete groupMemberDB;
    delete accountDB;
    delete profileDB;
}

int Group::getID() {
    return id;
}

Profile* Group::getProfile() {
    return profile;
}

bool Group::addMember(int accountID)
{
    memberIDList.push_back(accountID);
    memberNameList.push_back(accountDB->getUsername(accountID));
    return groupMemberDB->addGroupMember(id, accountID);
}

bool Group::addMember(QString username)
{
    int accountID = accountDB->retrieveAccountID(username);
    memberIDList.push_back(accountID);
    memberNameList.push_back(username);
    return groupMemberDB->addGroupMember(id, accountID);
}

bool Group::setAdmin(int accountID)
{
    if (groupMemberDB->setAdmin(id, accountID)) {
        //erase member from member list
        memberIDList.erase(std::remove(memberIDList.begin(), memberIDList.end(), accountID), memberIDList.end());
        QString username = accountDB->getUsername(accountID);
        memberNameList.erase(std::remove(memberNameList.begin(), memberNameList.end(), username), memberNameList.end());

        //add member to admin list
        adminIDList.push_back(accountID);
        adminNameList.push_back(username);
        return true;
    }
    return false;
}

bool Group::setAdmin(QString username)
{
    int accountID = accountDB->retrieveAccountID(username);
    if (groupMemberDB->setAdmin(id, accountID)) {
        //erase member from member list
        memberIDList.erase(std::remove(memberIDList.begin(), memberIDList.end(), accountID), memberIDList.end());
        memberNameList.erase(std::remove(memberNameList.begin(), memberNameList.end(), username), memberNameList.end());

        //add member to admin list
        adminIDList.push_back(accountID);
        adminNameList.push_back(username);
        return true;
    }
    return false;
}
