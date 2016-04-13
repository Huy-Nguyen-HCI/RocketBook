#include "scrapbook.h"

int Scrapbook::idCnt = 0;

Scrapbook::Scrapbook()
{
    id=idCnt;
    idCnt++;
    //construct all lists from database
    constructContentContainers();
}

Scrapbook::Scrapbook(int id)
{
    this->id = id;
    idCnt = id;
    idCnt++;
    idCnt++;


    //construct all lists from database
    constructContentContainers();
}

Scrapbook::~Scrapbook()
{
    delete blogDB;
    delete tweetDB;
    delete multimediaDB;
    delete accountDB;
}

void Scrapbook::constructContentContainers()
{
    //create the database connections
    blogDB = new BlogDB("../database/contentDB.sqlite");
    tweetDB = new TweetDB("../database/contentDB.sqlite");
    multimediaDB = new MultimediaDB("../database/contentDB.sqlite");
    commentDB = new CommentDB("../database/contentDB.sqlite");
    accountDB = new AccountDB("../database/accountDB.sqlite");


    //reconstruct all blogs
    std::vector<BlogInfoType> blogInfo = blogDB->retrieveAllBlogInfo(this->id);
    for (unsigned int i = 0; i < blogInfo.size(); i++) {
        int blogID = std::get<0>(blogInfo[i]);
        int accountID = std::get<1>(blogInfo[i]);
        QString blogTitle = std::get<3>(blogInfo[i]);
        QString blogContent = std::get<4>(blogInfo[i]);
        bool privacy = std::get<5>(blogInfo[i]);

        Blog* newBlog = new Blog(blogID,
                                 accountDB->getUsername(accountID),
                                 blogTitle,
                                 blogContent);
        if (privacy) { newBlog->setPrivate();}

        blogList.push_back(newBlog);
    }

    //reconstruct all tweets
    std::vector<TweetInfoType> tweetInfo = tweetDB->retrieveAllTweetInfo(this->id);
    for (unsigned int i = 0; i < tweetInfo.size(); i++) {
        int tweetID = std::get<0>(tweetInfo[i]);
        int accountID = std::get<1>(tweetInfo[i]);
        QString tweetContent = std::get<3>(tweetInfo[i]);
        bool privacy = std::get<4>(tweetInfo[i]);

        Tweet* newTweet = new Tweet(tweetID,
                                   accountDB->getUsername(accountID),
                                   tweetContent);
        if (privacy) { newTweet->setPrivate();}

        tweetList.push_back(newTweet);
    }

    //reconstruct all multimedia
    std::vector<MultimediaInfoType> multimediaInfo = multimediaDB->retrieveAllMultimediaInfo(this->id);
    for (unsigned int i = 0; i < multimediaInfo.size(); i++) {
        int multimediaID = std::get<0>(multimediaInfo[i]);
        int accountID = std::get<1>(multimediaInfo[i]);
        QString multimediaTitle = std::get<3>(multimediaInfo[i]);
        QString multimediaDescription = std::get<4>(multimediaInfo[i]);
        QString multimediaContent = std::get<5>(multimediaInfo[i]);
        bool privacy = std::get<6>(multimediaInfo[i]);

        Multimedia* newMultimedia = new Multimedia(multimediaID,
                                                   accountDB->getUsername(accountID),
                                                   multimediaTitle,
                                                   multimediaDescription,
                                                   multimediaContent);
        if (privacy) { newMultimedia->setPrivate();}

        mediaList.push_back(newMultimedia);
    }

    //reconstruct all comments
    for (unsigned int i = 0; i < blogList.size(); i++) {
        int blogID = blogList[i]->getID();
        std::vector<CommentInfoType> commentInfo = commentDB->retrieveAllCommentInfo(blogID);
        for (unsigned int i = 0; i < commentInfo.size(); i++) {
            int commentID = std::get<0>(commentInfo[i]);
            int accountID = std::get<1>(commentInfo[i]);
            QString commentContent = std::get<3>(commentInfo[i]);
            Comment* newComment = new Comment(commentID,
                                              accountDB->getUsername(accountID),
                                              commentContent);
            blogList[i]->addComment(newComment);
        }
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

Blog* Scrapbook::addBlog(QString username, QString title, QString content, bool privacy)
{
    //pull out latest PostID
    int blogID = blogDB->getMaxPostID() + 1;

    //create new blog
    Blog* newBlog = new Blog(blogID, username, title, content);
    if(privacy) { newBlog->setPrivate(); }

    //push back into the storage.
    blogList.push_back(newBlog);

    //add blog into the database
    blogDB->addBlog(blogID,
                    accountDB->retrieveAccountID(username),
                    this->id,
                    title,
                    content,
                    privacy);
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

Tweet *Scrapbook::addTweet(QString username, QString content, bool privacy){
    //pull out last tweetID
    int tweetID = tweetDB->getMaxPostID() + 1;

    //create new tweet
    Tweet* newTweet = new Tweet(id, username, content);
    if(privacy) { newTweet->setPrivate(); }

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

Multimedia *Scrapbook::addMedia(QString username, QString title, QString description, QString content, bool privacy){
    //pull out latest ID
    int mediaID = multimediaDB->getMaxPostID() + 1;

    //create new media
    Multimedia* newMedia = new Multimedia(mediaID, username, title, description, content);
    if(privacy) {newMedia->setPrivate();}

    //push back new media into media list
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

