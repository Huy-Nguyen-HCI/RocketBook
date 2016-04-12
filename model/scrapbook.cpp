#include "scrapbook.h"

int Scrapbook::idCnt = 0;

Scrapbook::Scrapbook()
{
    id=idCnt;
    idCnt++;
    blogDB = new BlogDB("../database/contentDB.sqlite");
    tweetDB = new TweetDB("../database/contentDB.sqlite");
    multimediaDB = new MultimediaDB("../database/contentDB.sqlite");

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


Blog *Scrapbook::addBlog(Blog* newBlog){
    blogList.push_back(newBlog);
    //store blog in DB
    return newBlog;
}

Blog* Scrapbook::addBlog(std::string username, std::string title, std::string content)
{
    //pull out latest BlogID
    int blogID = blogDB->
    Blog* newBlog = new Blog(blogID, username, title, content);
    blogList.push_back(newBlog);
    //store blog in DB
    return newBlog;
}

Tweet *Scrapbook::addTweet(Tweet* newTweet){
    tweetList.push_back(newTweet);
    //store tweet in DB
    return newTweet;
}

Tweet *Scrapbook::addTweet(std::string username, std::string content){
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

Multimedia *Scrapbook::addMedia(std::string username, std::string title, std::string description, std::string content){
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

