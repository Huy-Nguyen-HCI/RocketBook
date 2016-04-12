#include "scrapbook.h"

int Scrapbook::idCnt = 0;

Scrapbook::Scrapbook()
{
    id=idCnt;
    idCnt++;
    //construct all lists from database
    constructContentContainer();
}

Scrapbook::Scrapbook(int id)
{
    this->id = id;
    idCnt = id;
    idCnt++;
    idCnt++;


    //construct all lists from database
    constructContentContainer();
}

Scrapbook::~Scrapbook()
{
    delete blogDB;
    delete tweetDB;
    delete multimediaDB;
    delete accountDB;
}

Scrapbook::constructContentContainers()
{
    blogDB = new BlogDB("../database/contentDB.sqlite");
    tweetDB = new TweetDB("../database/contentDB.sqlite");
    multimediaDB = new MultimediaDB("../database/contentDB.sqlite");
    accountDB = new AccountDB("../database/accountDB.sqlite");

    std::vector<BlogInfoType> blogInfo = blogDB->retrieveAllBlogInfo(this->id);
    for (unsigned int i = 0; i < blogInfo.size(); i++) {
        int blogID = std::get<0>(blogInfo[i]);
        int accountID = std::get<1>(blogInfo[i]);
        int scrapbookID = std::get<2>(blogInfo[i]);
        QString blogTitle = std::get<3>(blogInfo[i]);
        QString blogContent = std::get<4>(blogInfo[i]);
        int privacy = std::get<5>(blogInfo[i]);

        Blog* newBlog = new Blog(blogID,
                                 accountDB->getUsername(accountID),
                                 blogTitle,
                                 blogContent);
        if (privacy) { newBlog->setPrivate();}

        blogList.push_back(newBlog);
    }

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
    int blogID = blogDB->getMaxPostID() + 1;

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
    //pull out last tweetID
    int tweetID = tweetDB->getMaxPostID() + 1;

    //create new tweet
    Tweet* newTweet = new Tweet(id, username, content);

    //add tweet into storage
    tweetList.push_back(newTweet);

    //add tweet into database
    tweetDB->addTweet(tweetID,
                      accountDB->retrieveAccountID(username),
                      this->id,
                      content,
                      newTweet->getPrivacy());
    return newTweet;
}

Multimedia *Scrapbook::addMedia(Multimedia* newMedia){
    mediaList.push_back(newMedia);

    //store media in DB
    int accountID = accountDB->retrieveAccountID(newMedia->getAuthorUsername());
    multimediaDB->addMultimedia(newMedia->getID(),
                                accountID,
                                this->id,
                                newMedia->getTitle(),
                                newMedia->getDescription(),
                                newMedia->getContent(),
                                newMedia->getPrivacy());
    return newMedia;
}

Multimedia *Scrapbook::addMedia(QString username, QString title, QString description, QString content){
    //pull out latest ID
    int mediaID = multimediaDB->getMaxPostID() + 1;

    Multimedia* newMedia = new Multimedia(mediaID, username, title, description, content);
    mediaList.push_back(newMedia);

    //store media in DB
    multimediaDB->addMultimedia(mediaID,
                                accountDB->retrieveAccountID(username),
                                this->id,
                                title,
                                description,
                                content,
                                newMedia->getPrivacy());
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

