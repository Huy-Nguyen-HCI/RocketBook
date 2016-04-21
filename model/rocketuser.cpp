#include "rocketuser.h"



int RocketUser::idCnt = 0;



RocketUser::RocketUser(QString dbPath,
                       int id,
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

    profileDB = new ProfileDB (dbPath);
    accountDB = new AccountDB(dbPath);
    profile = new Profile(dbPath, fullName, photo, description);
    profileDB->addProfile(profile->getID(),
                          profile->getFullName(),
                          profile->getPicturePath(),
                          profile->getDescription(),
                          profile->getScrapbook()->getID());
    groupController = new GroupController(dbPath, id);
    friendController = new FriendController(dbPath, id);
    chatController= new ChatController(dbPath, id);
    feed = new Feed(dbPath, friendController, groupController);

}

RocketUser::RocketUser(QString dbPath,
                       int id,
                       QString username,
                       int profileID,
                       int adminRights = 0)
{
    this->id = id;
    idCnt = id;
    idCnt++;
    this->username = username;
    this->adminRights = adminRights;
    profileDB = new ProfileDB (dbPath);
    accountDB = new AccountDB(dbPath);


    if (profileDB->profileExists(profileID)) {
        ProfileInfoType profileInfo = profileDB->retrieveProfileInfo(profileID);

        QString fullName = std::get<1>(profileInfo);
        QString photo = std::get<2>(profileInfo);
        QString description = std::get<3>(profileInfo);
        int scrapbookID = std::get<4>(profileInfo);
        profile = new Profile(dbPath, profileID, fullName, photo, description, scrapbookID);
    } else {
        qDebug() << "Profile does not exists.";
    }

    groupController = new GroupController(dbPath, id);
    friendController = new FriendController(dbPath, id);
    feed = new Feed(dbPath, friendController, groupController);
}

RocketUser::~RocketUser() {
    delete profile;
    delete friendController;
    delete groupController;
    delete chatController;
    delete feed;
    delete profileDB;
    delete accountDB;
}

Profile* RocketUser::getProfile(){
    return profile;
}

bool RocketUser::changeProfileDescription(QString description){
    profile->setDescription(description);
    return profileDB->changeDescription(profile->getID(), description);
}

bool RocketUser::changePhoto(QString path) {
    profile->setPicturePath(path);
    return profileDB->changePhoto(profile->getID(), path);
}

