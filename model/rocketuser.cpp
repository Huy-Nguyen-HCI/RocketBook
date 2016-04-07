#include "rocketuser.h"



int RocketUser::idCnt = 0;

RocketUser::RocketUser()
{
    id=idCnt;
    idCnt++;
    profile = new Profile();
}

RocketUser::RocketUser(int id)
{
    this->id = id;
    idCnt = id;
    idCnt++;
    profile = new Profile();
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
