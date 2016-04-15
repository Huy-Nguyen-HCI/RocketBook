#include "rocketuser.h"



int RocketUser::idCnt = 0;

RocketUser::RocketUser(QString fullName, QString photo, QString description)
{
    id=idCnt;
    idCnt++;
    profile = new Profile(fullName, photo, description);
    ProfileDB profileDB("../database/profileDB.sqlite");
    profileDB.addProfile(profile->getID(),
                         profile->getFullName(),
                         profile->getPicturePath(),
                         profile->getDescription(),
                         profile->getScrapbook()->getID());
}

RocketUser::RocketUser(int id)
{
    this->id = id;
    idCnt = id;
    idCnt++;

    ProfileDB profileDB("../database/profileDB.sqlite");
//    int profileID =

//    profile = new Profile();
//    profileDB.addProfile(profile->getID(),
//                         profile->getFullName(),
//                         profile->getPicturePath(),
//                         profile->getDescription(),
//                         profile->getScrapbook()->getID());
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
