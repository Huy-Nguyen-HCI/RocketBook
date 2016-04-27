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
    void displayScrapbook();
    void displayBlog(Blog* blog, int row);
    void displayTweet(Tweet* tweet, int row);

private:
    Scrapbook* scrapbook;
};


#endif // POSTUI_H
