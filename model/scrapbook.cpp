#include "scrapbook.h"

int Scrapbook::idCnt = 0;

Scrapbook::Scrapbook()
{
    id=idCnt;
    idCnt++;
    blogDB = new BlogDB("../database/contentDB.sqlite");
    tweetDB = new TweetDB("../database/contentDB.sqlite");
    multimediaDB = new MultimediaDB("../database/contentDB.sqlite");
    accountDB = new AccountDB("../database/accountDB.sqlite");

    //construct blogList from database
    //construct tweetList from database
    //construct mediaList from database
    //construct postList from database
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
    int blogID = blogDB->getMaxBlogID() + 1; //pull out latest BlogID

    Blog* newBlog = new Blog(blogID, username, title, content); //create new blog
    blogList.push_back(newBlog); //push back into the storage.

    //add blog into the database

    int accountID = accountDB->retrieveAccountID(username);

    blogDB->addBlog(blogID,
                    accountID,
                    this->id,
                    title,
                    content,
                    newBlog->getPrivacy());
    return newBlog;
}

Tweet *Scrapbook::addTweet(Tweet* newTweet){
    tweetList.push_back(newTweet);
    //store tweet in DB
    return newTweet;
}

Tweet *Scrapbook::addTweet(QString username, QString content){
    //pull out latest ID
    Tweet* newTweet = new Tweet(username, content);
    //store tweet in DB
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

