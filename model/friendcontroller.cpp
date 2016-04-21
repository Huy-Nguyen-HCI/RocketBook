#include "friendcontroller.h"

FriendController::FriendController(QString dbPath, int accountID)
{
    this->dbPath = dbPath;
    friendDB = new FriendDB(dbPath);
    accountDB = new AccountDB(dbPath, "AccountFriend");
    this->accountID = accountID;

    updateFriendList();

}

void FriendController::updateFriendList(){
    friendIdList.empty();
    friendNameList.clear();

    friendIdList= friendDB->retrieveAllFriends(accountID);
    for(unsigned int i=0; i<friendIdList.size(); i++){
        friendNameList.append(accountDB->getUsername(friendIdList.at(i)));
    }
}

QStringList FriendController::getFriendNames(){

    return friendNameList;
}

std::vector<int> FriendController::getFriendIds(){
    return friendIdList;
}




FriendController::AddFriendStatus FriendController::addFriend(QString friendname){

    int friendId = accountDB->retrieveAccountID(friendname);
    QString username = accountDB->getUsername(accountID);

    if (!accountDB->accountExists(friendname) || !accountDB->accountExists(username)){
        std::cerr << "Account does not exist." << std::endl;
        return FriendController::FriendNotExist;
    }

    if(friendDB->friendshipExists(accountID,friendId)) {
        std::cerr << "You are already friend with " << friendname.toStdString() <<std::endl;
        return FriendController::AlreadyFriend;
    }

    if (friendDB->addFriend(accountID,friendId)) {
        std::cout << "You are now friends with " << friendname.toStdString() << "!" << std::endl;
        return FriendController::AddSuccessful;
    }

    return FriendController::AddFailed;
}

FriendController::DeleteFriendStatus FriendController::deleteFriend(QString friendname){

    int friendId = accountDB->retrieveAccountID(friendname);

    if (!friendDB->friendshipExists(accountID,friendId)) {
        std::cerr << "Friendship does not exist." << std::endl;
        return FriendController::FriendshipNotExist;
    }

    else{

        friendDB->removeFriend(accountID,friendId);
        std::cout << "You are no longer friends with " << friendname.toStdString() << "." << std::endl;
        return FriendController::DeleteSuccessful;
    }
}