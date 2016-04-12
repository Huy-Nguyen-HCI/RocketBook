#include "scrapbook.h"

int Scrapbook::idCnt = 0;

Scrapbook::Scrapbook()
{
    id=idCnt;
    idCnt++;

    //construct
    blogDB = new BlogDB("../database/contentDB.sqlite");
    tweetDB = new TweetDB("../database/contentDB.sqlite");
    multimediaDB = new MultimediaDB("../database/contentDB.sqlite");
    accountDB = new AccountDB("../database/accountDB.sqlite");

    ///construct blogList from database
    ///construct tweetList from database
    ///construct mediaList from database
    ///construct postList from database
}

Scrapbook::Scrapbook(int id)
{
    this->id = id;
    idCnt = id;
    idCnt++;
    idCnt++;

    blogDB = new BlogDB("../database/contentDB.sqlite");
    tweetDB = new TweetDB("../database/contentDB.sqlite");
    multimediaDB = new MultimediaDB("../database/contentDB.sqlite");
}

Scrapbook::~Scrapbook()
{
    delete blogDB;
    delete tweetDB;
    delete multimediaDB;
    delete accountDB;
}


Blog *Scrapbook::addBlog(Blog* newBlog){
    blogList.push_back(newBlog);

    //add blog into the database
    int accountID = accountDB->retrieveAccountID(newBlog->getAuthorUsername());
    blogDB->addBlog(newBlog->getID(),
                    accountID,
                    this->id,
                    newBlog->getTitle(),
                    newBlog->getContent(),
                    newBlog->getPrivacy());
    return newBlog;
}

Blog* Scrapbook::addBlog(QString username, QString title, QString content)
{
    //pull out latest PostID
    int blogID = blogDB->getMaxBlogID() + 1;

    //create new blog
    Blog* newBlog = new Blog(blogID, username, title, content);

    //push back into the storage.
    blogList.push_back(newBlog);

    //add blog into the database
    blogDB->addBlog(blogID,
                    accountDB->retrieveAccountID(username),
                    this->id,
                    title,
                    content,
                    newBlog->getPrivacy());
    return newBlog;
}

Tweet *Scrapbook::addTweet(Tweet* newTweet){
    tweetList.push_back(newTweet);

    //add tweet into the database
    int accountID = accountDB->retrieveAccountID(newTweet->getAuthorUsername());
    tweetDB->addTweet(newTweet->getID(),
                     accountID,
                     this->id,
                     newTweet->getContent(),
                     newTweet->getPrivacy());
    return newTweet;
}

Tweet *Scrapbook::addTweet(QString username, QString content){
    ///pull out latest ID
    Tweet* newTweet = new Tweet(username, content);
    ///store tweet in DB
    return newTweet;
}

Multimedia *Scrapbook::addMedia(Multimedia* newMedia){
    //pull out latest ID
    mediaList.push_back(newMedia);
    //store media in DB
    return newMedia;
}

Multimedia *Scrapbook::addMedia(QString username, QString title, QString description, QString content){
    //pull out latest ID
    Multimedia* newMedia = new Multimedia(username, title, description, content);
    mediaList.push_back(newMedia);
    //store media in DB
    return newMedia;
}




//Blog* Scrapbook::getBlog(int num){
//    return blogList->at(num);
//}

//Tweet* Scrapbook::getTweet(int num){
//    return tweetList->at(num);
//}

//Multimedia* Scrapbook::getMedia(int num){
//    return mediaList->at(num);
//}

