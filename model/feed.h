#ifndef FEED_H
#define FEED_H

#include <vector>
#include "friendcontroller.h"
#include "groupcontroller.h"
#include "scrapbook.h"



class Feed{

public:
    Feed(FriendController* friendController, GroupController* groupController);
    void updatePostList();

private:
    FriendController* friendController;
    GroupController* groupController;
    std::vector<Post*> postList;

};

#endif // FEED_H
