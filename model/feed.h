#ifndef FEED_H
#define FEED_H

#include <vector>
#include "friendcontroller.h"
#include "groupcontroller.h"
#include "scrapbook.h"



class Feed{

public:
    Feed(QString dbPath, FriendController* friendController, GroupController* groupController);
    void updatePostList();
    std::vector<Post*> getFeed();


private:
    QString dbPath;
    AccountDB* accountDB;
    ProfileDB* profileDB;
    FriendController* friendController;
    std::vector<Scrapbook*> scrapbookList;
    GroupController* groupController;
    std::vector<Post*> postList;

    bool static comparePost(Post* a, Post* b);

};

#endif // FEED_H
