#include "feed.h"

Feed::Feed(QString dbPath, FriendController *friendController, GroupController *groupController)
{
    this->dbPath = dbPath;
    this->friendController = friendController;
    this->groupController = groupController;
    accountDB = new AccountDB(dbPath, "accountFeed");
    profileDB = new ProfileDB(dbPath, "profileFeed");
}

std::vector<Post*> Feed::getFeed() {
    return postList;
}

void Feed::updatePostList()
{
    postList.empty();
    scrapbookList.empty();

    //update all friends' scrapbooks
    std::vector<int> friendIDList = friendController->getFriendIds();
    for(unsigned int i = 0; i < friendIDList.size(); i++) {
        int profileID = accountDB->getProfileID(friendIDList[i]);
        int scrapbookID = profileDB->retrieveScrapbookID(profileID);
        Scrapbook* newScrapbook = new Scrapbook(dbPath, scrapbookID);
        scrapbookList.push_back(newScrapbook);
    }

    //update all groups' scrapbooks
    std::vector<Group*> allGroups = groupController->getAllGroups();
    for (unsigned int i = 0; i < allGroups.size(); i++) {
        scrapbookList.push_back(allGroups[i]->getProfile()->getScrapbook());
    }

    //push all public posts from scrapbook list into the postList
    for (unsigned int i = 0; i < scrapbookList.size(); i++) {
        Scrapbook* currentScrapbook = scrapbookList[i];
        std::vector<Post*> allPost = currentScrapbook->getAllPublicPosts();
        postList.reserve(postList.size() + allPost.size());
        postList.insert(postList.end(), allPost.begin(), allPost.end());
    }

    //sort all posts according to ID
    std::sort(postList.begin(), postList.end(), Feed::comparePost);

}

bool Feed::comparePost(Post *a, Post *b)
{
    return a->getID() > b->getID();
}

