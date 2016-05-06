#ifndef POSTUI_H
#define POSTUI_H

#include "screen.h"


class ScrapbookUI: public Screen
{
public:
    ScrapbookUI(AccountController* accountControl);

    void drawScreen(int v);
    void takeCommand(int selection);


    void postBlog();
    void postTweet();
    void postMedia();
    void makeHTML();
    int displayScrapbook();
    void viewBlog(int index);
    void postComment(int blogIndex);
    bool checkType(int scrapbookIndex);
    void displayBlog(Blog* blog, int row);
    void displayTweet(Tweet* tweet, int row);

private:
    Scrapbook* scrapbook;


    QString profileToHTML();
    QString friendsToHTML();
    QString buildContentHTML();
    QString blogToHTML(Blog *blog);
    QString tweetToHTML(Tweet *tweet);
    QString multimediaToHTML(Multimedia *media);
    void writeToHTMLFile(QString htmlText);
};


#endif // POSTUI_H
