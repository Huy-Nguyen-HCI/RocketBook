#include "rocketuser.h"



int RocketUser::idCnt;

RocketUser::RocketUser()
{
    id=idCnt;
    idCnt++;
    profile = new Profile();
}

int RocketUser::getPlayerId(){
    return id;
}

Profile* RocketUser::getProfile(){
    return profile;
}

void RocketUser::addFriend(int friendUserId){
    friendList->push_back(friendUserId);


}
