#include "scrapbook.h"

ScrapBook::ScrapBook()
{

}



void ScrapBook::addBlog(Blog* newBlog){
    blogList.push_back(newBlog);
}

void ScrapBook::addTweet(Tweet* newTweet){
    tweetList.push_back(newTweet);
}

void ScrapBook::addMedia(Multimedia* newMedia){
    mediaList.push_back(newMedia);
}





//Blog* ScrapBook::getBlog(int num){
//    return blogList->at(num);
//}

//Tweet* ScrapBook::getTweet(int num){
//    return tweetList->at(num);
//}

//Multimedia* ScrapBook::getMedia(int num){
//    return mediaList->at(num);
//}

