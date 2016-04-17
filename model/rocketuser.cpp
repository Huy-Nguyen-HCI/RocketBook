#include "rocketuser.h"



int RocketUser::idCnt = 0;

RocketUser::RocketUser(int id,
                       QString username,
                       QString fullName,
                       QString photo,
                       QString description,
                       int adminRights)
{
    this->id = id;
    idCnt = id;
    idCnt++;
    this->username = username;
    this->adminRights = adminRights;
    profileDB = new ProfileDB ("../database/profileDB.sqlite", "Profiles");
    profile = new Profile(fullName, photo, description);
    profileDB->addProfile(profile->getID(),
                          profile->getFullName(),
                          profile->getPicturePath(),
                          profile->getDescription(),
                          profile->getScrapbook()->getID());

}

RocketUser::RocketUser(int id,
                       QString username,
                       int profileID,
                       int adminRights = 0)
{
    this->id = id;
    idCnt = id;
    idCnt++;
    this->username = username;
    this->adminRights = adminRights;

    profileDB = new ProfileDB ("../database/profileDB.sqlite", "Profiles");
    if (profileDB->profileExists(profileID)) {
        ProfileInfoType profileInfo = profileDB->retrieveProfileInfo(profileID);

        QString fullName = std::get<1>(profileInfo);
        QString photo = std::get<2>(profileInfo);
        QString description = std::get<3>(profileInfo);
        int scrapbookID = std::get<4>(profileInfo);
        profile = new Profile(profileID, fullName, photo, description, scrapbookID);
    } else {
        qDebug() << "Profile does not exists.";
    }
}

RocketUser::~RocketUser() {
    delete profile;
}

int RocketUser::getID(){
    return id;
}

Profile* RocketUser::getProfile(){
    return profile;
}

void RocketUser::addFriend(int friendUserId){
    friendList->push_back(friendUserId);


}
