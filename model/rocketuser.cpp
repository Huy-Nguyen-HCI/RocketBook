#include "rocketuser.h"



int RocketUser::id_cnt;

RocketUser::RocketUser()
{
id=id_cnt;
id_cnt++;
profile=new Profile();
}

int RocketUser::getPlayerId(){
    return id;
}

Profile* RocketUser::getProfile(){
    return profile;
}
