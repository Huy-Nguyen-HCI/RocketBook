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
}

RocketUser::~RocketUser() {
    delete profile;
}

Profile* RocketUser::getProfile(){
    return profile;
}

bool RocketUser::changeProfileDescription(QString description){
    ///add change method in profile
    return profileDB->changeDescription(profile->getID(), description);
}

bool RocketUser::changePhoto(QString path) {
    ///add change method in photo
    return profileDB->changeDescription(profile->getID(), path);
}


//void RocketUser::updateFriendList(){
//    friendIdList.empty();
//    friendNameList.clear();

//    friendIdList= friendDB->retrieveAllFriends(accountDB->retrieveAccountID(username));
//    for(unsigned int i=0; i<friendIdList.size(); i++){
//        friendNameList.append(accountDB->getUsername(friendIdList.at(i)));
//    }

//}

//QStringList RocketUser::getFriendNames(){

//    return friendNameList;
//}

//std::vector<int> RocketUser::getFriendIds(){
//    return friendIdList;
//}




//RocketUser::AddFriendStatus RocketUser::addFriend(QString friendname){
//    int userId, friendId;

//    userId=accountDB->retrieveAccountID(username);
//    friendId=accountDB->retrieveAccountID(friendname);

//    if (!accountDB->accountExists(friendname) || !accountDB->accountExists(username)){
//        std::cerr << "Account does not exist." << std::endl;
//        return RocketUser::FriendNotExist;
//    }

//    if(friendDB->friendshipExists(userId,friendId)) {
//        std::cerr << "You are already friend with " << friendname.toStdString() <<std::endl;
//        return RocketUser::AlreadyFriend;
//    }

//    if (friendDB->addFriend(userId,friendId)) {
//        std::cout << "You are now friends with " << friendname.toStdString() << "!" << std::endl;
//        return RocketUser::Successful;
//    }

//    return RocketUser::Failed;
//}

//void RocketUser::deleteFriend(QString friendname){

//    int userId, friendId;

//    userId=accountDB->retrieveAccountID(username);
//    friendId=accountDB->retrieveAccountID(friendname);

//    if (!friendDB->friendshipExists(userId,friendId))
//        std::cerr << "Friendship does not exist." << std::endl;
//        return RocketUser::FriendshipNotExist;
//    }

//    else{

//        friendDB->removeFriend(userId,friendId);
//        std::cout << "You are no longer friends with " << friendname.toStdString() << "." << std::endl;
//    }
//}
