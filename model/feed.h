#ifndef FEED_H
#define FEED_H

#include <vector>
#include "friendcontroller.h"
#include "groupcontroller.h"
#include "scrapbook.h"



class Feed{

public:
    /**
     * @brief Constructs feed
     * @param dbPath Database path
     * @param friendController FriendController
     * @param groupController GroupController
     */
    Feed(QString dbPath, FriendController* friendController, GroupController* groupController);
    /**
     * @brief Destructs feed
     */
    ~Feed();
    /**
     * @brief Updates post list
     */
    void updatePostList();

    /**
     * @brief getFeed
     * Compiles a list of post which is the user's feed
     * @return the user's feed (a vector of Posts*)
     */
    std::vector<Post*> getFeed();

    /**
     * @brief getBlog
     * @param id Blog Id
     * @return returns blog with specified Id
     */
    Blog* getBlog(int id);


private:
    QString dbPath;
    AccountDB* accountDB;
    ProfileDB* profileDB;
    FriendController* friendController;
    std::vector<Scrapbook*> scrapbookList;
    GroupController* groupController;
    std::vector<Post*> postList;

    /**
     * @brief compare Post
     * @param a Post a
     * @param b Post b
     * @return True if posts are identical
     */
    bool static comparePost(Post* a, Post* b);

};

#endif // FEED_H
