#include "scrapbook.h"

int Scrapbook::idCnt = 0;

Scrapbook::Scrapbook()
{
    id=idCnt;
    idCnt++;
}

Scrapbook::Scrapbook(int id)
{
    this->id = id;
    idCnt = id;
    idCnt++;
    idCnt++;
}


void Scrapbook::addBlog(Blog* newBlog){
    blogList.push_back(newBlog);
}

void Scrapbook::addTweet(Tweet* newTweet){
    tweetList.push_back(newTweet);
}

void Scrapbook::addMedia(Multimedia* newMedia){
    mediaList.push_back(newMedia);
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

