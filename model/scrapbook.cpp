#include "scrapbook.h"

ScrapBook::ScrapBook()
{

}



void ScrapBook::addBlog(Blog* newBlog){
    blogList->push_back(newBlog);
}

void ScrapBook::addTweet(Tweet* newTweet){
    TweetList->push_back(newTweet);
}

void ScrapBook::addMedia(MultimediaContent* newMedia){
    mediaList->push_back(newMedia);
}





Comment* ScrapBook::getBlog(int num){
    return blogList->at(num);
}

Tweet* ScrapBook::getTweet(int num){
    return tweetList->at(num);
}

MultimediaContent* ScrapBook::getMedia(int num){
    return mediaList->at(num);
}

