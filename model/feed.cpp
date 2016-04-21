#include "feed.h"

Feed::Feed(FriendController *friendController, GroupController *groupController)
{
    this->friendController = friendController;
    this->groupController = groupController;
}

void Feed::updatePostList()
{
    std::vector<int> friendIDList = friendController->getFriendIds();
    std::vector<Group*> getAllGroups = groupController->getAllGroups();

//    postList.push_back();
}
